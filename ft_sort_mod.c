/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_mod.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 12:23:44 by tsomacha          #+#    #+#             */
/*   Updated: 2024/12/03 14:16:28 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void ft_printlst(t_list *list)
// {
// 	t_list *node = list;
// 	ft_printf("list : \n----------------------------\n");
// 	ft_printf("pos{%d} dat{%d} pre{%d} nex{%d}\n",node->position,node->data,node->prev->data,node->next->data);
// 	node = node->next;
// 	while(node != list)
// 	{
// 		ft_printf("pos{%d} dat{%d} pre{%d} nex{%d}\n",node->position,node->data,node->prev->data,node->next->data);
// 		node = node->next;
// 	}
// 	ft_printf("\n----------------------------\n");
// }

// void ft_printstk(t_stack *stack)
// {
// 	t_list *node = stack->top;
// 	ft_printf("Stack : \n----------------------------\n");
// 	while(node)
// 	{
// 		ft_printf("data : {%d}\n",node->data);
// 		node = node->next;
// 	}
// 	ft_printf("\n----------------------------\n");
// }

int	check_top(t_stack *stack_a, t_stack *stack_b, t_list *guide)
{
	t_list	*top_a;
	int		top_b;
	int		next_b;
	int		bottom_b;

	top_a = ft_list_get_node(guide, ft_stk_peek(stack_a));
	top_b = ft_stk_peek(stack_b);
	next_b = ft_stk_get_next(stack_b);
	bottom_b = ft_stk_get_bottom(stack_b);
	if (top_a->prev->data == top_b)
		return (pa(stack_a, stack_b));
	else if (top_a->next->data == top_b)
			return (ra(stack_a) && pa(stack_a, stack_b));
	else if (top_a->prev->data == next_b)
			return (rb(stack_b) && pa(stack_a, stack_b));
	else if (top_a->next->data == next_b)
			return (rr(stack_a, stack_b) && pa(stack_a, stack_b));
	else if(top_a->prev->data == bottom_b)
			return (rrb(stack_b) && pa(stack_a, stack_b));
	return (0);
}

int	check_next(t_stack *stack_a, t_stack *stack_b, t_list *guide)
{
	t_list	*next_a;
	int	top_b;
	int	next_b;

	next_a = ft_list_get_node(guide, ft_stk_get_next(stack_a));
	top_b = ft_stk_peek(stack_b);
	next_b = ft_stk_get_next(stack_b);
	if (next_a->prev->data == top_b)
		return (ra(stack_a) && pa(stack_a, stack_b));
	else if (next_a->prev->data == next_b)
			return (rr(stack_a, stack_b) && pa(stack_a, stack_b));
	return (0);
}

int	check_bottom(t_stack *stack_a, t_stack *stack_b, t_list *guide)
{
	t_list	*bottom_a;
	int	top_b;
	int	next_b;
	int	bottom_b;

	bottom_a = ft_list_get_node(guide, ft_stk_get_bottom(stack_a));
	top_b = ft_stk_peek(stack_b);
	next_b = ft_stk_get_next(stack_b);
	bottom_b = ft_stk_get_bottom(stack_b);
	if (bottom_a->prev->data == top_b)
		return (rra(stack_a) && pa(stack_a, stack_b));
	else if (bottom_a->next->data == top_b)
			return (pa(stack_a, stack_b));
	else if (bottom_a->next->data == next_b)
			return (rb(stack_b) && pa(stack_a, stack_b));
	else if (bottom_a->prev->data == bottom_b)
			return (rrr(stack_a, stack_b) && pa(stack_a, stack_b));
	else if (bottom_a->next->data == bottom_b)
			return (rrb(stack_b) && pa(stack_a, stack_b));
	return (0);
}

void	ft_stk_set_index_abs(t_stack *stack)
{
	int count = 0;
	t_list *node = stack->top;
	while(node)
	{
		node->position = count;
		count++;
		node = node->next;
	}
}

int ft_stk_get_index(t_stack *stack, int value)
{
	t_list *node = stack->top;
	while(node)
	{
		if(node->data == value)
			return (node->position);
		node = node->next;
	}
	return (-1);
}

void	ft_make_head_up(t_stack *stack_a, t_list *guide)
{
	int min = ft_list_get_value(guide,0);
	int index = ft_stk_get_index(stack_a, min);
	int size = ft_stk_get_size(stack_a);
	if(index < (size/2))
	{
		while(stack_a->top->data != min)
			ra(stack_a);
	}
	else
	{
		while(stack_a->top->data != min)
			rra(stack_a);
	}
}

void	ft_move(t_stack *stack_a, t_stack *stack_b, t_list *guide)
{
	while(!ft_stk_is_empty(stack_b))
	{
		check_top(stack_a, stack_b, guide);
		check_next(stack_a, stack_b, guide);
		check_bottom(stack_a, stack_b, guide);
		rrb(stack_b);
		rrb(stack_b);
	}
}

void	solution_moderate(t_stack *stack_a, t_stack *stack_b, int size)
{
	t_list *guide = ft_list_get_list(stack_a);
	int pivot = ft_list_get_value(guide, (size/2) - 1);
	while(size > 3)
	{
		pb(stack_b, stack_a);
		if(stack_b->top->data < pivot)
			rb(stack_b);
		size--;
	}
	solution_three(stack_a);
	ft_move(stack_a, stack_b, guide);
	ft_make_head_up(stack_a, guide);
	ft_list_clear(guide);
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_step_two.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 12:23:44 by tsomacha          #+#    #+#             */
/*   Updated: 2024/12/03 14:16:28 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_top_a(t_stack *stack_a, t_stack *stack_b, t_list *guide)
{
	int		top_b;
	int		next_b;
	int		bottom_b;
	t_list	*top_a;

	top_b = ft_stk_peek(stack_b);
	next_b = ft_stk_get_next(stack_b);
	bottom_b = ft_stk_get_bottom(stack_b);
	top_a = ft_list_get_node(guide, ft_stk_peek(stack_a));
	if (top_a->next->data == top_b)
		return (ra(stack_a), 1);
	else if (top_a->prev->data == next_b)
		return (rb(stack_b), 1);
	else if (top_a->prev->data == bottom_b)
		return (rrb(stack_b), 1);
	else if (top_a->next->data == next_b)
		return (rr(stack_a, stack_b), 1);
	return (0);
}

static int	check_bottom_a(t_stack *stack_a, t_stack *stack_b, t_list *guide)
{
	int		top_b;
	int		next_b;
	int		bottom_b;
	t_list	*bottom_a;

	bottom_a = ft_list_get_node(guide, ft_stk_get_bottom(stack_a));
	top_b = ft_stk_peek(stack_b);
	next_b = ft_stk_get_next(stack_b);
	bottom_b = ft_stk_get_bottom(stack_b);
	if (bottom_a->next->data == next_b)
		return (rb(stack_b), 1);
	else if (bottom_a->next->data == bottom_b)
		return (rrb(stack_b), 1);
	else if (bottom_a->prev->data == top_b)
		return (rra(stack_a), 1);
	else if (bottom_a->prev->data == bottom_b)
		return (rrr(stack_a, stack_b), 1);
	return (0);
}

static int	check_next_a(t_stack *stack_a, t_stack *stack_b, t_list *guide)
{
	int		top_b;
	int		next_b;
	t_list	*next_a;

	next_a = ft_list_get_node(guide, ft_stk_get_next(stack_a));
	top_b = ft_stk_peek(stack_b);
	next_b = ft_stk_get_next(stack_b);
	if (next_a->prev->data == top_b)
		return (ra(stack_a), 1);
	else if (next_a->prev->data == next_b)
		return (rr(stack_a, stack_b), 1);
	return (0);
}

int	two_step(t_stack *stack_a, t_stack *stack_b, t_list *guide)
{
	if (check_top_a(stack_a, stack_b, guide))
		return (pa(stack_a, stack_b), 1);
	if (check_bottom_a(stack_a, stack_b, guide))
		return (pa(stack_a, stack_b), 1);
	if (check_next_a(stack_a, stack_b, guide))
		return (pa(stack_a, stack_b));
	return (0);
}

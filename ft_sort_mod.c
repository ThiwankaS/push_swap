/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_mod.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 12:23:44 by tsomacha          #+#    #+#             */
/*   Updated: 2025/02/09 14:26:38 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_make_head_up(t_stack *stack_a, t_list *guide)
{
	int	min;
	int	index;
	int	size;
	int	max_iter;

	min = ft_list_get_value(guide, 0);
	index = ft_stk_get_index_abs(stack_a, min);
	size = ft_stk_get_size(stack_a);
	max_iter = size;
	if (index < (size / 2))
	{
		while (stack_a->top->data != min && max_iter--)
			ra(stack_a);
	}
	else
	{
		while (stack_a->top->data != min && max_iter--)
			rra(stack_a);
	}
}

void	ft_pass(t_stack *stack_a, t_list *guide)
{
	t_list	*top_a;
	t_list	*bottom_a;

	top_a = ft_list_get_node(guide, ft_stk_peek(stack_a));
	bottom_a = ft_list_get_node(guide, ft_stk_get_bottom(stack_a));
	while (top_a->prev->data == bottom_a->data)
	{
		ra(stack_a);
		top_a = ft_list_get_node(guide, ft_stk_peek(stack_a));
		bottom_a = ft_list_get_node(guide, ft_stk_get_bottom(stack_a));
	}
}

void	ft_move(t_stack *stack_a, t_stack *stack_b, t_list *guide)
{
	int	response;

	response = 1;
	while (!ft_stk_is_empty(stack_b))
	{
		ft_pass(stack_a, guide);
		while (response)
		{
			while (response)
				response = one_step(stack_a, stack_b, guide);
			response = 1;
			while (response)
				response = two_step(stack_a, stack_b, guide);
			response = 1;
			while (response)
				response = three_step(stack_a, stack_b, guide);
			response = 1;
			while (response)
				response = four_step(stack_a, stack_b, guide);
		}
		response = 1;
		ft_rotate_opt(stack_a, stack_b, guide);
	}
}

void	solution_moderate(t_stack *stack_a, t_stack *stack_b, int size)
{
	t_list	*guide;
	int		length;
	int		limit;
	int		pivot;

	guide = ft_list_get_list(stack_a);
	length = ft_list_size(guide);
	limit = ft_list_get_value(guide, (length - 2));
	pivot = ft_list_get_value(guide, (length / 2));
	while (!ft_stk_is_empty(stack_a) && size)
	{
		if (ft_stk_peek(stack_a) < limit)
		{
			pb(stack_b, stack_a);
			if (ft_stk_peek(stack_b) < pivot)
				rb(stack_b);
		}
		else
			ra(stack_a);
		size--;
	}
	solution_three(stack_a);
	ft_move(stack_a, stack_b, guide);
	ft_make_head_up(stack_a, guide);
	ft_list_clear(guide);
}

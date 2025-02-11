/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opt_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 12:23:44 by tsomacha          #+#    #+#             */
/*   Updated: 2024/12/03 14:16:28 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_opt(t_stack *stack_a, t_stack *stack_b, t_list *guide)
{
	int	min_count;
	int	min_index;
	int	value;
	int	size;
	int	index;
	int	count;
	int	candidates_a[] = {
		ft_list_get_node(guide, ft_stk_peek(stack_a))->prev->data,
		ft_list_get_node(guide, ft_stk_peek(stack_a))->next->data,
		ft_list_get_node(guide, ft_stk_get_next(stack_a))->prev->data,
		ft_list_get_node(guide, ft_stk_get_next(stack_a))->next->data,
		ft_list_get_node(guide, ft_stk_get_bottom(stack_a))->prev->data,
		ft_list_get_node(guide, ft_stk_get_bottom(stack_a))->next->data
	};

	size = ft_stk_get_size(stack_b);
	min_count = size;
	min_index = size - 1;
	value = 0;
	for (int i = 0; i < 6; i++)
	{
		index = ft_stk_get_index_abs(stack_b, candidates_a[i]);
		if (index >= 0)
		{
			if (index < size / 2)
				count = index;
			else
				count = size - index;
			if (count < min_count)
			{
				min_count = count;
				min_index = index;
				value = candidates_a[i];
			}
		}
	}
	if (ft_is_exsit_eql(stack_b, value))
	{
		if (min_index < (size / 2))
		{
			while (stack_b->top->data != value)
				rb(stack_b);
		}
		else
		{
			while (stack_b->top->data != value)
				rrb(stack_b);
		}
	}
}

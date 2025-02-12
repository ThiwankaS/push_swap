/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opt_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 12:23:44 by tsomacha          #+#    #+#             */
/*   Updated: 2025/02/11 14:33:09 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_best_index(t_stack *stack_b, int *arr)
{
	t_info	info;
	int		value;

	info.count = 0;
	info.min_count = ft_stk_get_size(stack_b);
	info.size = ft_stk_get_size(stack_b);
	while (info.count < 6)
	{
		info.index = ft_stk_get_index_abs(stack_b, arr[info.count]);
		if (info.index >= 0)
		{
			if ((info.index < info.size / 2) && info.index < info.min_count)
			{
				info.min_count = info.index;
				value = arr[info.count];
			}
			else if ((info.size - info.index) < info.min_count)
			{
				info.min_count = info.size - info.index;
				value = arr[info.count];
			}
		}
		info.count++;
	}
	return (value);
}

void	ft_rotate_opt(t_stack *stack_a, t_stack *stack_b, t_list *guide)
{
	int	value;
	int	size;
	int	index;
	int	points[6];

	points[0] = ft_list_get_node(guide, ft_stk_peek(stack_a))->prev->data;
	points[1] = ft_list_get_node(guide, ft_stk_peek(stack_a))->next->data;
	points[2] = ft_list_get_node(guide, ft_stk_get_next(stack_a))->prev->data;
	points[3] = ft_list_get_node(guide, ft_stk_get_next(stack_a))->next->data;
	points[4] = ft_list_get_node(guide, ft_stk_get_bottom(stack_a))->prev->data;
	points[5] = ft_list_get_node(guide, ft_stk_get_bottom(stack_a))->next->data;
	value = get_best_index(stack_b, points);
	index = ft_stk_get_index_abs(stack_b, value);
	size = ft_stk_get_size(stack_b);
	if (ft_is_exsit_eql(stack_b, value))
	{
		while (stack_b->top->data != value)
		{
			if (index < size / 2)
				rb(stack_b);
			else
				rrb(stack_b);
		}
	}
}

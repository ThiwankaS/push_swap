/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_comp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 12:23:44 by tsomacha          #+#    #+#             */
/*   Updated: 2024/12/03 14:16:28 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_bit_size(int value)
{
	int	count;

	count = 0;
	if (value < 0)
		return (-1);
	if (value == 0)
		return (1);
	while (value > 0)
	{
		count++;
		value = value >> 1;
	}
	return (count);
}

void	solution_complex(t_stack *stack_a, t_stack *stack_b, int size)
{
	t_list	*guide;
	int		max_bit;
	int		count;
	int		step;

	count = 0;
	guide = ft_list_get_list(stack_a);
	max_bit = ft_bit_size(size - 1);
	ft_stk_set_index(stack_a, guide);
	while (count <= max_bit && !ft_stk_is_sorted(stack_a))
	{
		step = 0;
		while (step++ < size)
		{
			if ((stack_a->top->position >> count) & 1)
				ra(stack_a);
			else
				pb(stack_b, stack_a);
		}
		while (!ft_stk_is_empty(stack_b))
			pa(stack_a, stack_b);
		ft_stk_set_index(stack_a, guide);
		count++;
	}
	ft_list_clear(guide);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 12:23:44 by tsomacha          #+#    #+#             */
/*   Updated: 2024/12/03 14:16:28 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_stack *stack_a, t_stack *stack_b)
{
	int	size;

	if (!stack_a)
		return ;
	if (ft_stk_is_empty(stack_a))
		return ;
	if (ft_stk_is_sorted(stack_a))
		return ;
	size = ft_stk_get_size(stack_a);
	if (size == 1)
		return ;
	if (size == 2)
		solution_two(stack_a);
	if (size == 3)
		solution_three(stack_a);
	if (size == 4)
		solution_four(stack_a, stack_b, size);
	if (size == 5)
		solution_five(stack_a, stack_b, size);
	if (size > 5)
		solution_complex(stack_a, stack_b, size);
}

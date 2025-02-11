/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_step_four.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 12:23:44 by tsomacha          #+#    #+#             */
/*   Updated: 2024/12/03 14:16:28 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	four_step(t_stack *stack_a, t_stack *stack_b, t_list *guide)
{
	t_list	*next_a;
	int		bottom_b;

	next_a = ft_list_get_node(guide, ft_stk_get_next(stack_a));
	bottom_b = ft_stk_get_bottom(stack_b);
	if (next_a->next->data == bottom_b)
	{
		rrb(stack_b);
		ra(stack_a);
		ra(stack_a);
		pa(stack_a, stack_b);
		return (1);
	}
	return (0);
}

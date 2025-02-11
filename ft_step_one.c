/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_step_one.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 12:23:44 by tsomacha          #+#    #+#             */
/*   Updated: 2025/02/11 11:51:40 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_top_b(t_list *top_a, t_list *bottom_a, int top_b)
{
	if (top_a->prev->data == top_b)
		return (1);
	else if (bottom_a->next->data == top_b)
		return (1);
	else
		return (0);
}

int	one_step(t_stack *stack_a, t_stack *stack_b, t_list *guide)
{
	t_list	*top_a;
	t_list	*bottom_a;
	int		top_b;
	int		bottom_b;

	top_a = ft_list_get_node(guide, ft_stk_peek(stack_a));
	bottom_a = ft_list_get_node(guide, ft_stk_get_bottom(stack_a));
	top_b = ft_stk_peek(stack_b);
	bottom_b = ft_stk_get_bottom(stack_b);
	if (check_top_b(top_a, bottom_a, top_b))
	{
		pa(stack_a, stack_b);
		return (1);
	}
	else if (top_a->next->data == bottom_b)
	{
		rrb(stack_b);
		ra(stack_a);
		pa(stack_a, stack_b);
		return (1);
	}
	return (0);
}

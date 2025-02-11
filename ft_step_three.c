/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_step_three.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 12:23:44 by tsomacha          #+#    #+#             */
/*   Updated: 2024/12/03 14:16:28 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	three_step(t_stack *stack_a, t_stack *stack_b, t_list *guide)
{
	t_list	*top_a;
	t_list	*next_a;
	t_list	*bottom_a;
	int		top_b;
	int		next_b;
	int		bottom_b;

	top_a = ft_list_get_node(guide, ft_stk_peek(stack_a));
	next_a = ft_list_get_node(guide, ft_stk_get_next(stack_a));
	bottom_a = ft_list_get_node(guide, ft_stk_get_bottom(stack_a));
	top_b = ft_stk_peek(stack_b);
	next_b = ft_stk_get_next(stack_b);
	bottom_b = ft_stk_get_bottom(stack_b);
	if (top_a->next->data == bottom_b)
	{
		rrb(stack_b);
		ra(stack_a);
		pa(stack_a, stack_b);
		return (1);
	}
	else if (bottom_a->prev->data == next_b)
	{
		rb(stack_b);
		rra(stack_a);
		pa(stack_a, stack_b);
		return (1);
	}
	else if (next_a->next->data == top_b)
	{
		ra(stack_a);
		ra(stack_a);
		pa(stack_a, stack_b);
		return (1);
	}
	else if (next_a->next->data == next_b)
	{
		rr(stack_a, stack_b);
		ra(stack_a);
		pa(stack_a, stack_b);
		return (1);
	}
	else if (next_a->prev->data == bottom_b)
	{
		rrb(stack_b);
		pa(stack_a, stack_b);
		sa(stack_a);
		return (1);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_easy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 12:23:44 by tsomacha          #+#    #+#             */
/*   Updated: 2024/12/03 14:16:28 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	solution_two(t_stack *stack_a)
{
	if (!ft_stk_is_sorted(stack_a))
		sa(stack_a);
}

void	solution_three(t_stack *stack_a)
{
	while (!ft_stk_is_sorted(stack_a))
	{
		if (stack_a->top->data > ft_stk_get_bottom(stack_a))
			ra(stack_a);
		else if (stack_a->top->data > ft_stk_get_next(stack_a))
			sa(stack_a);
		else if (ft_stk_get_next(stack_a) > ft_stk_get_bottom(stack_a))
			rra(stack_a);
	}
}

void	solution_four(t_stack *stack_a, t_stack *stack_b, int size)
{
	t_list	*list;
	int		pivot;

	list = ft_list_get_list(stack_a);
	pivot = ft_list_get_value(list, size - 3 - 1);
	while (size > 0 && ft_is_exist_sml(stack_a, pivot))
	{
		if (ft_stk_peek(stack_a) == pivot)
			pb(stack_b, stack_a);
		else
			ra(stack_a);
		size--;
	}
	solution_three(stack_a);
	pa(stack_a, stack_b);
	ft_list_clear(list);
}

void	solution_five(t_stack *stack_a, t_stack *stack_b, int size)
{
	t_list	*list;
	int		pivot;

	list = ft_list_get_list(stack_a);
	pivot = ft_list_get_value(list, size - 3 -1);
	while (size > 0 && ft_is_exist_sml(stack_a, pivot))
	{
		if (ft_stk_peek(stack_a) <= pivot)
			pb(stack_b, stack_a);
		else
			ra(stack_a);
		size--;
	}
	solution_three(stack_a);
	while (!ft_stk_is_empty(stack_b))
	{
		if (ft_stk_is_sorted(stack_b))
			rrb(stack_b);
		pa(stack_a, stack_b);
	}
	ft_list_clear(list);
}

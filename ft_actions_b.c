/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 12:23:44 by tsomacha          #+#    #+#             */
/*   Updated: 2024/12/03 14:16:28 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sb(t_stack *stack_b)
{
	swap(stack_b);
	ft_printf("sb\n");
	return (1);
}

int	rb(t_stack *stack_b)
{
	rotate(stack_b);
	ft_printf("rb\n");
	return (1);
}

int	rrb(t_stack *stack_b)
{
	reverse_rotate(stack_b);
	ft_printf("rrb\n");
	return (1);
}

int	pb(t_stack *stack_b, t_stack *stack_a)
{
	ft_stk_push(stack_b, ft_stk_pop(stack_a));
	ft_printf("pb\n");
	return (1);
}

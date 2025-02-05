/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 12:23:44 by tsomacha          #+#    #+#             */
/*   Updated: 2024/12/03 14:16:28 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sa(t_stack *stack_a)
{
	swap(stack_a);
	ft_printf("sa\n");
	return (1);
}

int	ra(t_stack *stack_a)
{
	rotate(stack_a);
	ft_printf("ra\n");
	return (1);
}

int	rra(t_stack *stack_a)
{
	reverse_rotate(stack_a);
	ft_printf("rra\n");
	return (1);
}

int	pa(t_stack *stack_a, t_stack *stack_b)
{
	ft_stk_push(stack_a, ft_stk_pop(stack_b));
	ft_printf("pa\n");
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stk_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 12:23:44 by tsomacha          #+#    #+#             */
/*   Updated: 2024/12/03 14:16:28 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	t_list	*top;
	t_list	*next;

	if (!stack || ft_stk_get_size(stack) < 2)
		return ;
	top = stack->top;
	next = top->next;
	top->next = next->next;
	if (next->next)
		next->next->prev = top;
	next->prev = NULL;
	next->next = top;
	top->prev = next;
	stack->top = next;
}

void	rotate(t_stack *stack)
{
	t_list	*top;
	t_list	*next;
	t_list	*bottom;

	if (!stack || ft_stk_get_size(stack) < 2)
		return ;
	top = stack->top;
	next = top->next;
	bottom = stack->top;
	while (bottom && bottom->next)
		bottom = bottom->next;
	bottom->next = top;
	next->prev = NULL;
	top->prev = bottom;
	top->next = NULL;
	stack->top = next;
}

void	reverse_rotate(t_stack *stack)
{
	t_list	*top;
	t_list	*last;
	t_list	*bottom;

	if (!stack || ft_stk_get_size(stack) < 2)
		return ;
	top = stack->top;
	bottom = stack->top;
	while (bottom && bottom->next)
	{
		last = bottom;
		bottom = bottom->next;
	}
	top->prev = bottom;
	bottom->prev = NULL;
	bottom->next = top;
	last->next = NULL;
	stack->top = bottom;
}

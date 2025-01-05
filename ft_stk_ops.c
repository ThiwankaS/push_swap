/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stk_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 13:04:23 by tsomacha          #+#    #+#             */
/*   Updated: 2025/01/05 14:52:02 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

void	stk_swap(t_stack *stack)
{
	t_list	*top;
	t_list	*next;

	if (!stack || !stack->top || !stack->top->next)
		return ;
	top = stack->top;
	next = top->next;
	top->next = next->next;
	if (next->next)
		next->next->previous = top;
	top->previous = next;
	next->previous = NULL;
	next->next = top;
	stack->top = next;
}

void	stk_rotate(t_stack *stack)
{
	t_list	*top;
	t_list	*next;
	t_list	*bottom;

	if (!stack || !stack->top || !stack->top->next)
		return ;
	top = stack->top;
	next = top->next;
	if (next)
		next->previous = NULL;
	stack->top = next;
	bottom = stack->top;
	while (bottom && bottom->next)
		bottom = bottom->next;
	if (bottom)
		bottom->next = top;
	top->previous = bottom;
	top->next = NULL;
}

void	stk_reverse_rotate(t_stack *stack)
{
	t_list	*top;
	t_list	*bottom;
	t_list	*second_last;

	if (!stack || !stack->top || !stack->top->next)
		return ;
	top = stack->top;
	bottom = stack->top;
	while (bottom->next)
		bottom = bottom->next;
	second_last = bottom->previous;
	if (second_last)
		second_last->next = NULL;
	bottom->previous = NULL;
	bottom->next = top;
	stack->top = bottom;
}

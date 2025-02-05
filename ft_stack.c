/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 12:23:44 by tsomacha          #+#    #+#             */
/*   Updated: 2024/12/03 14:16:28 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

void	ft_stk_init(t_stack *stack)
{
	if (!stack)
		return ;
	stack->top = NULL;
}

bool	ft_stk_is_empty(t_stack *stack)
{
	if (!stack)
		return (false);
	return (stack->top == NULL);
}

bool	ft_stk_push(t_stack *stack, int data)
{
	t_list	*node;

	if (!stack)
		return (false);
	node = malloc(sizeof(t_list));
	if (!node)
		return (false);
	node->data = data;
	node->next = stack->top;
	if (stack->top)
		stack->top->prev = node;
	stack->top = node;
	return (true);
}

int	ft_stk_pop(t_stack *stack)
{
	t_list	*node;
	int		value;

	if (!stack || ft_stk_is_empty(stack))
		return (-1);
	node = stack->top;
	value = node->data;
	if (stack->top->next)
	{
		stack->top->next->prev = NULL;
		stack->top = stack->top->next;
	}
	else
	{
		stack->top = NULL;
	}
	free(node);
	return (value);
}

int	ft_stk_peek(t_stack *stack)
{
	if (!stack || ft_stk_is_empty(stack))
		return (-1);
	return (stack->top->data);
}

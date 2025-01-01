/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 08:53:33 by tsomacha          #+#    #+#             */
/*   Updated: 2024/12/31 11:56:23 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

void	stk_init(t_stack *stack)
{
	stack->top = NULL;
}

bool	stk_isempty(t_stack *stack)
{
	return (stack->top == NULL);
}

bool	stk_push(t_stack *stack, int value)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (false);
	node->data = value;
	node->next = stack->top;
	node->previous = NULL;
	if (stack->top != NULL)
	{
		stack->top->previous = node;
	}
	stack->top = node;
	return (true);
}

int	stk_pop(t_stack *stack)
{
	t_list	*node;
	int		value;

	if (stk_isempty(stack))
	{
		return (-1);
	}
	node = stack->top;
	value = stack->top->data;
	stack->top = stack->top->next;
	if (stack->top != NULL)
	{
		stack->top->previous = NULL;
	}
	free(node);
	return (value);
}

int	stk_peek(t_stack *stack)
{
	if (stk_isempty(stack))
		return (-1);
	return (stack->top->data);
}

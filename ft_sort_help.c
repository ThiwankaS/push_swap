/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_help.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 12:23:44 by tsomacha          #+#    #+#             */
/*   Updated: 2024/12/03 14:16:28 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stk_get_next(t_stack *stack)
{
	if (!stack || ft_stk_get_size(stack) < 2)
		return (-1);
	if (stack->top->next)
		return (stack->top->next->data);
	else
		return (-1);
}

int	ft_stk_get_bottom(t_stack *stack)
{
	t_list	*node;

	if (!stack || ft_stk_get_size(stack) < 2)
		return (-1);
	node = stack->top;
	while (node && node->next)
		node = node->next;
	return (node->data);
}

void	ft_stk_set_index(t_stack *stack, t_list *guide)
{
	t_list	*node;

	if (!stack)
		return ;
	node = stack->top;
	while (node)
	{
		node->position = ft_list_get_node(guide, node->data)->position;
		node = node->next;
	}
}

int	ft_stk_get_size(t_stack *stack)
{
	t_list	*node;
	int		count;

	count = 0;
	if (!stack)
		return (count);
	node = stack->top;
	while (node)
	{
		count++;
		node = node->next;
	}
	return (count);
}

bool	ft_is_exist(t_stack *stack, int value)
{
	t_list	*node;

	if (!stack)
		return (false);
	node = stack->top;
	while (node)
	{
		if (node->data <= value)
			return (true);
		node = node->next;
	}
	return (false);
}

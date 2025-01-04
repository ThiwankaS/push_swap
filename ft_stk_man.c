/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stk_man.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 13:15:39 by tsomacha          #+#    #+#             */
/*   Updated: 2024/12/31 14:42:36 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_stack.h"

bool	stk_contain_duplicates(t_stack *stack)
{
	t_list	*node;
	t_list	*start;
	int		value;

	node = stack->top;
	while (node)
	{
		value = node->data;
		start = node->next;
		while (start)
		{
			if (value == start->data)
				return (true);
			start = start->next;
		}
		node = node->next;
	}
	return (false);
}

bool	stk_is_sorted(t_stack *stack, bool ascending)
{
	t_list	*current_node;
	t_list	*next_node;

	current_node = stack->top;
	next_node = current_node->next;
	while (current_node && next_node)
	{
		if (ascending)
		{
			if (current_node->data > next_node->data)
				return (false);
		}
		else
		{
			if (current_node->data < next_node->data)
				return (false);
		}
		current_node = next_node;
		next_node = current_node->next;
	}
	return (true);
}

bool	stk_exit(t_stack *stack)
{
	while (!stk_isempty(stack))
		stk_pop(stack);
	return (true);
}

int	stk_get_size(t_stack *stack)
{
	int		count;
	t_list	*node;

	count = 0;
	node = stack->top;
	while (node)
	{
		count++;
		node = node->next;
	}
	return (count);
}

int	stk_get_bottom(t_stack *stack)
{
	int		count;
	t_list	*node_prev;
	t_list	*node_next;

	count = 0;
	node_next = stack->top;
	while (node_next)
	{
		count++;
		node_prev = node_next;
		node_next = node_next->next;
	}
	return (node_prev->data);
}

int	stk_get_next(t_stack *stack)
{
	t_list	*node;
	t_list	*node_next;

	node = stack->top;
	node_next = node->next;
	if(!node_next)
		return (node->data);
	return (node_next->data);
}

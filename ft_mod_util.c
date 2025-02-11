/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mod_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 12:23:44 by tsomacha          #+#    #+#             */
/*   Updated: 2024/12/03 14:16:28 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stk_set_index_abs(t_stack *stack)
{
	int		count;
	t_list	*node;

	count = 0;
	node = stack->top;
	while (node)
	{
		node->position = count++;
		node = node->next;
	}
}

int	ft_stk_get_index_abs(t_stack *stack, int value)
{
	t_list	*node;

	node = stack->top;
	ft_stk_set_index_abs(stack);
	while (node)
	{
		if (node->data == value)
			return (node->position);
		node = node->next;
	}
	return (-1);
}

bool	ft_is_exsit_eql(t_stack *stack, int value)
{
	t_list	*node;

	node = stack->top;
	while (node)
	{
		if (node->data == value)
			return (true);
		node = node->next;
	}
	return (false);
}

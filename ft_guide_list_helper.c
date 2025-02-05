/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_guide_list_helper.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 12:23:44 by tsomacha          #+#    #+#             */
/*   Updated: 2024/12/03 14:16:28 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_list_make_circular(t_list *list)
{
	t_list	*first;
	t_list	*last;

	if (!list)
		return ;
	first = list;
	last = list;
	while (last && last->next)
		last = last->next;
	first->prev = last;
	last->next = first;
}

void	ft_list_set_index(t_list *list)
{
	t_list	*node;
	int		count;

	count = 0;
	if (!list)
		return ;
	node = list;
	while (node)
	{
		node->position = count;
		count++;
		node = node->next;
	}
}

int	ft_list_get_value(t_list *list, int index)
{
	t_list	*current;

	if (!list)
		return (-1);
	current = list;
	while (current)
	{
		if (current->position == index)
			return (current->data);
		current = current->next;
	}
	return (-1);
}

bool	ft_stk_is_sorted(t_stack *stack)
{
	t_list	*node;

	if (!stack)
		return (false);
	if (ft_stk_is_empty(stack) || ft_stk_get_size(stack) == 1)
		return (true);
	node = stack->top;
	while (node && node->next)
	{
		if (node->data > node->next->data)
			return (false);
		node = node->next;
	}
	return (true);
}

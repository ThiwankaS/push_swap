/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_guide_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 12:23:44 by tsomacha          #+#    #+#             */
/*   Updated: 2024/12/03 14:16:28 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_list_create(t_stack *stack)
{
	t_list	*list;
	t_list	*node;

	ft_list_init(&list);
	if (!stack)
		return (NULL);
	node = stack->top;
	while (node)
	{
		ft_list_add(&list, node->data);
		node = node->next;
	}
	return (list);
}

void	swap_nodes(t_list **list, t_list *current)
{
	t_list	*before;
	t_list	*after;

	before = current->prev;
	after = current->next;
	if (before)
		before->next = after;
	else
		*list = after;
	current->next = after->next;
	if (after->next)
		after->next->prev = current;
	current->prev = after;
	after->next = current;
	after->prev = before;
}

void	ft_list_sort(t_list **list)
{
	t_list	*current;
	bool	sorted;

	if (!list ||!*list)
		return ;
	sorted = false;
	while (sorted == false)
	{
		sorted = true;
		current = *list;
		while (current->next)
		{
			if (current->data > current->next->data)
			{
				swap_nodes(list, current);
				sorted = false;
			}
			else
				current = current->next;
		}
	}
}

t_list	*ft_list_get_node(t_list *list, int value)
{
	t_list	*ptr;

	if (!list)
		return (NULL);
	ptr = list;
	while (ptr && ptr->next)
	{
		if (ptr->data == value)
			return (ptr);
		ptr = ptr->next;
	}
	return (NULL);
}

t_list	*ft_list_get_list(t_stack *stack)
{
	t_list	*list;

	list = ft_list_create(stack);
	ft_list_sort(&list);
	ft_list_set_index(list);
	ft_list_make_circular(list);
	return (list);
}

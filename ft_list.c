/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 12:23:44 by tsomacha          #+#    #+#             */
/*   Updated: 2024/12/03 14:16:28 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_init(t_list **list)
{
	*list = NULL;
}

bool	ft_list_is_empty(t_list **list)
{
	return (*list == NULL);
}

void	ft_list_add(t_list **list, int data)
{
	t_list	*node;
	t_list	*ptr;

	node = malloc(sizeof(t_list));
	node->next = NULL;
	node->data = data;
	if (!*list)
	{
		*list = node;
		node->prev = NULL;
	}
	else
	{
		ptr = *list;
		while (ptr && ptr->next)
			ptr = ptr->next;
		node->prev = ptr;
		ptr->next = node;
	}
}

void	ft_list_clear(t_list *list)
{
	t_list	*current;
	t_list	*next;
	t_list	*head;

	if (!list)
		return ;
	current = list;
	head = list;
	if (current->next == current)
	{
		free(current);
		return ;
	}
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
		if (current == head)
		{
			current = NULL;
		}
	}
}

int	ft_list_size(t_list *list)
{
	int		count;
	t_list	*current;

	count = 0;
	current = list;
	if (current->next)
	{
		count++;
		current = current->next;
	}
	while (current && current != list)
	{
		count++;
		current = current->next;
	}
	return (count);
}

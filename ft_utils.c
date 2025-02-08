/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 12:23:44 by tsomacha          #+#    #+#             */
/*   Updated: 2024/12/03 14:16:28 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stk_print(t_stack *stack)
{
	t_list	*node;

	if (!stack)
		return ;
	node = stack->top;
	while (node)
	{
		ft_printf("stack [%d] : [%d]\n", node->data, node->position);
		node = node->next;
	}
}

bool	ft_stk_clear(t_stack *stack)
{
	t_list	*node;
	t_list	*next;

	if (!stack || ft_stk_is_empty(stack))
		return (true);
	node = stack->top;
	while (node)
	{
		next = node->next;
		free(node);
		node = next;
	}
	stack->top = NULL;
	return (!stack->top);
}

bool	ft_exit(char **ptr)
{
	int	count;

	if (!ptr || !*ptr)
		return (false);
	count = 0;
	while (ptr && ptr[count])
	{
		free(ptr[count]);
		count++;
	}
	free(ptr);
	return (true);
}

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

bool	ft_add_to_stack(char **arr, int count, t_stack *stack)
{
	long	data;

	data = ft_atol(arr[count]);
	if (data >= INT_MIN && data <= INT_MAX)
	{
		if (!ft_stk_push(stack, (int)data))
		{
			ft_stk_clear(stack);
			ft_error();
			return (false);
		}
		return (true);
	}
	else
	{
		ft_stk_clear(stack);
		ft_error();
		return (false);
	}
}

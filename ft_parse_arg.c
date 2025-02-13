/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 12:23:44 by tsomacha          #+#    #+#             */
/*   Updated: 2025/02/11 17:40:07 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	ft_isvalid(char *str)
{
	int	count;

	count = 0;
	while (str[count] == ' ' || (str[count] >= 9 && str[count] <= 13))
		count++;
	if (!str[count])
		return (false);
	if (str[count] == '-' || str[count] == '+')
		count++;
	if (!str[count])
		return (false);
	while (str && str[count])
	{
		if (!ft_isdigit(str[count]))
			return (false);
		count++;
	}
	if (!str[count])
		return (true);
	return (false);
}

char	**ft_parse_argument(char **argv, int argc, int *start)
{
	char	**result;

	if (argc == 2)
		result = ft_get_numbers(argv, start);
	else
	{
		while (++(*start) < argc)
		{
			if (!ft_isvalid(argv[*start]))
				return (NULL);
		}
		result = argv;
	}
	return (result);
}

bool	ft_push_to_stack(char **arr, int argc, int *start, t_stack *stack)
{
	if (argc == 2)
	{
		while (--(*start) >= 0)
		{
			if (!ft_add_to_stack(arr, *start, stack))
			{
				free(arr[*start]);
				return (false);
			}
			else
				free(arr[*start]);
		}
		return (true);
	}
	else
	{
		while (--(*start) > 0)
		{
			if (!ft_add_to_stack(arr, *start, stack))
				return (false);
		}
		return (true);
	}
}

bool	ft_handle_argument(int argc, char **argv, t_stack *stack)
{
	char	**result;
	int		size;

	size = 0;
	result = ft_parse_argument(argv, argc, &size);
	if (!result)
		return (false);
	if (!ft_push_to_stack(result, argc, &size, stack))
	{
		if (argc == 2)
		{
			while (size--)
				free(result[size]);
			free(result);
		}
		return (false);
	}
	if (argc == 2)
		free(result);
	if (stk_contain_duplicates(stack))
		return (false);
	return (true);
}

bool	stk_contain_duplicates(t_stack *stack)
{
	t_list	*node;
	t_list	*start;
	int		value;

	if (!stack)
		return (false);
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

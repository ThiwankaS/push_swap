/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 13:15:39 by tsomacha          #+#    #+#             */
/*   Updated: 2024/12/31 14:42:36 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"
#include "libft.h"

bool	ft_isvalid(char *str)
{
	int	count;

	count = 0;
	while (str[count] == ' ' || (str[count] >= 9 && str[count] <= 13))
		count++;
	if (str[count] == '-' || str[count] == '+')
		count++;
	while (str && str[count])
	{
		if (!ft_isdigit(str[count]))
			return (false);
		count++;
	}
	return (true);
}

bool	ft_exit(char **ptr)
{
	int	count;

	count = 0;
	while (ptr && ptr[count])
	{
		free(ptr[count]);
		if (!ptr[count])
			return (false);
		count++;
	}
	free(ptr);
	if (!ptr)
		return (false);
	return (true);
}

char	**ft_parse_argument(char **argv, int argc, int *start)
{
	char	**result;

	if (argc == 2)
	{
		result = ft_split(argv[1], ' ');
		while (result && result[(*start)++])
		{
			if (!ft_isvalid(result[*start - 1]))
			{
				ft_exit(result);
				return (NULL);
			}
		}
		(*start)--;
	}
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

bool	ft_push_to_stack(char **arr, int argc, int count, t_stack *stack)
{
	if (argc == 2)
	{
		while (count >= 0)
		{
			if (!stk_push(stack, ft_atoi(arr[count])))
				return (ft_exit(arr));
			free(arr[count]);
			count--;
		}
		return (true);
	}
	else
	{
		while (count > 0)
		{
			if (!stk_push(stack, ft_atoi(arr[count])))
				return (false);
			count--;
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
	if (!ft_push_to_stack(result, argc, (size - 1), stack))
		return (false);
	if (argc == 2)
		free(result);
	return (true);
}

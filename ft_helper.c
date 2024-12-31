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
	int	sign;

	count = 0;
	sign = 0;
	while (str[count] == ' ' || (str[count] >= 9 && str[count] <= 13))
		count++;
	if (str[count] == '-' || str[count] == '+')
		count++;
	while(str && str[count])
	{
		if(!ft_isdigit(str[count]))
			return (false);
		count++;
	}
	return (true);
}

bool	ft_handle_argument(int argc, char **argv, t_stack *stack)
{
	char	**result;
	int		count;
	int		step;

	count = 0;
	step = 1;
	if(argc == 2)
	{
		result = ft_split(argv[1], ' ');
		while(result[count])
		{
			if(!ft_isvalid(result[count]))
				return (false);
			count++;
		}
		return (true);
	}
	else
	{
		while(step < argc)
		{
			if(ft_isvalid(argv[step]))
			{
				stk_push(stack, ft_atoi(argv[step]));
				ft_printf("added : %d\n", stk_peek(stack));
			}
			else
				return (false);
			step++;
		}
		return (true);
	}
}

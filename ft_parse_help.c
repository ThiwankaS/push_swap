/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_help.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 12:23:44 by tsomacha          #+#    #+#             */
/*   Updated: 2024/12/03 14:16:28 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	ft_pre_valid(char *str)
{
	int		word_count;
	int		count;
	bool	is_zero;

	word_count = ft_wordcount(str, ' ');
	count = 0;
	while (str && str[count] && !ft_isdigit(str[count]))
		count++;
	if (str[count] == '0' && ft_isdigit(str[count + 1]))
		is_zero = true;
	else
		is_zero = false;
	if (word_count == 0 || is_zero)
		return (false);
	return (true);
}

int	ft_wordcount(char const *s, char c)
{
	int	step;
	int	word_count;

	step = 0;
	word_count = 0;
	while (s[step] != '\0')
	{
		if (s[step] != c)
		{
			word_count++;
			while (s[step] != c && s[step] != '\0')
				step++;
			if (s[step] == '\0')
				return (word_count);
		}
		step++;
	}
	return (word_count);
}

char	**ft_get_numbers(char **argv, int *start)
{
	char	**result;

	if (!ft_pre_valid(argv[1]))
		return (NULL);
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
	return (result);
}

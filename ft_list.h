/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 12:23:44 by tsomacha          #+#    #+#             */
/*   Updated: 2024/12/03 14:16:28 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

# include <stdlib.h>
# include <stdbool.h>

typedef struct s_list
{
	struct s_list	*prev;
	struct s_list	*next;
	int				position;
	int				data;
}	t_list;

void	ft_list_init(t_list **list);
bool	ft_list_is_empty(t_list **list);
void	ft_list_add(t_list **list, int data);
void	ft_list_clear(t_list *list);
int		ft_list_size(t_list *list);

#endif

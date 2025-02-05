/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 12:23:44 by tsomacha          #+#    #+#             */
/*   Updated: 2024/12/03 14:16:28 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STACK_H
# define FT_STACK_H

# include <stdlib.h>
# include <stdbool.h>
# include "ft_list.h"

typedef struct s_stack
{
	t_list	*top;
}	t_stack;

void	ft_stk_init(t_stack *stack);
bool	ft_stk_is_empty(t_stack *stack);
bool	ft_stk_push(t_stack *stack, int data);
int		ft_stk_get_size(t_stack *stack);
int		ft_stk_pop(t_stack *stack);
int		ft_stk_peek(t_stack *stack);

#endif

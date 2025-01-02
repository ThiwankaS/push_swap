/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 08:53:33 by tsomacha          #+#    #+#             */
/*   Updated: 2024/12/31 14:36:29 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STACK_H
# define FT_STACK_H

# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdbool.h>

# include "libft.h"

typedef struct s_list
{
	struct s_list	*previous;
	struct s_list	*next;
	int				data;
}	t_list;

typedef struct s_stack
{
	t_list	*top;
}	t_stack;

void	stk_init(t_stack *stack);
bool	stk_push(t_stack *stack, int value);

int		stk_pop(t_stack *stack);
int		stk_peek(t_stack *stack);
bool	stk_isempty(t_stack *stack);

bool	ft_isvalid(char *str);
bool	ft_handle_argument(int argc, char **argv, t_stack *stack);
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   stk_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 13:04:23 by tsomacha          #+#    #+#             */
/*   Updated: 2025/01/05 14:52:02 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

void	solution_two(t_stack *stack)
{
	if(!stk_is_sorted(stack, true))
	{
		stk_swap(stack);
		ft_printf("sa\n");
	}
}

void	sort(t_stack *stack)
{
	if (!stack)
		return ;
	if (stk_isempty(stack))
		return ;
	if (stk_is_sorted(stack, true))
		return ;
	if (stk_get_size(stack) == 1)
		return ;
	if (stk_get_size(stack) == 2)
		solution_two(stack);
}

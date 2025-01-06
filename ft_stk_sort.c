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

void	solution_three(t_stack *stack)
{
	while(!stk_is_sorted(stack, true))
	{
		if(stack->top->data > stk_get_bottom(stack))
		{
			stk_rotate(stack);
			ft_printf("ra\n");
		}
		else if(stack->top->data > stk_get_next(stack))
		{
			stk_swap(stack);
			ft_printf("sa\n");
		}
		else if(stk_get_next(stack) > stk_get_bottom(stack))
		{
			stk_reverse_rotate(stack);
			ft_printf("rra\n");
		}
	}
}

void	sort(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a)
		return ;
	if (stk_isempty(stack_a))
		return ;
	if (stk_is_sorted(stack_a, true))
		return ;
	if (stk_get_size(stack_a) == 1)
		return ;
	if (stk_get_size(stack_a) == 2)
		solution_two(stack_a);
	if (stk_get_size(stack_a) == 3)
		solution_three(stack_a);
	if(!stk_isempty(stack_b))
		return ;
}

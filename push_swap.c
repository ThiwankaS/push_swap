/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 12:23:44 by tsomacha          #+#    #+#             */
/*   Updated: 2025/02/11 15:16:50 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	stack_a;
	t_stack	stack_b;

	ft_stk_init(&stack_a);
	ft_stk_init(&stack_b);
	if (argc > 1)
	{
		if (!ft_handle_argument(argc, argv, &stack_a))
		{
			ft_stk_clear(&stack_a);
			ft_error();
			return (0);
		}
	}
	sort_stack(&stack_a, &stack_b);
	ft_stk_clear(&stack_a);
	ft_stk_clear(&stack_b);
	return (0);
}

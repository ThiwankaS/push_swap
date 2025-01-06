/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 13:15:39 by tsomacha          #+#    #+#             */
/*   Updated: 2025/01/05 14:50:41 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"
#include "libft.h"

void	stk_print(t_stack *stack)
{
	t_list	*temp;
	int		count;

	count = 0;
	temp = stack->top;
	while (temp)
	{
		ft_printf("item [%d] : data [%d]\n", count, temp->data);
		temp = temp->next;
		count++;
	}
}

int	main(int argc, char *argv[])
{
	t_stack	stack_a;
	t_stack stack_b;

	stk_init(&stack_a);
	stk_init(&stack_b);
	if (argc > 1)
	{
		if (!ft_handle_argument(argc, argv, &stack_a))
		{
			ft_printf("Error!\n");
			return (stk_exit(&stack_a));
		}
	}
	else
		ft_printf("Error!\n");
	sort(&stack_a, &stack_b);
	while (!stk_isempty(&stack_a))
		stk_pop(&stack_a);
	return (0);
}

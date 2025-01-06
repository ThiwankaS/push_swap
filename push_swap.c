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
	t_stack	stack;

	stk_init(&stack);
	if (argc > 1)
	{
		if (!ft_handle_argument(argc, argv, &stack))
		{
			ft_printf("Error!\n");
			return (stk_exit(&stack));
		}
	}
	else
		ft_printf("Error!\n");
	sort(&stack);
	while (!stk_isempty(&stack))
		stk_pop(&stack);
	return (0);
}

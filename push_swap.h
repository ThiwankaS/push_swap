/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 12:23:44 by tsomacha          #+#    #+#             */
/*   Updated: 2024/12/03 14:16:28 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include "ft_stack.h"
# include "ft_list.h"
# include "ft_printf.h"
# include "libft.h"

int		sa(t_stack *stack_a);
int		ra(t_stack *stack_a);
int		rra(t_stack *stack_a);
int		pa(t_stack *stack_a, t_stack *stack_b);

int		sb(t_stack *stack_b);
int		rb(t_stack *stack_b);
int		rrb(t_stack *stack_b);
int		pb(t_stack *stack_b, t_stack *stack_a);

int		ss(t_stack *stack_a, t_stack *stack_b);
int		rr(t_stack *stack_a, t_stack *stack_b);
int		rrr(t_stack *stack_a, t_stack *stack_b);

long	ft_atol(const char *nptr);

void	ft_list_make_circular(t_list *list);
void	ft_list_set_index(t_list *list);
int		ft_list_get_value(t_list *list, int index);
bool	ft_stk_is_sorted(t_stack *stack);

void	ft_list_sort(t_list **list);
void	swap_nodes(t_list **list, t_list *current);
t_list	*ft_list_create(t_stack *stack);
t_list	*ft_list_get_list(t_stack *stack);
t_list	*ft_list_get_node(t_list *list, int value);

char	**ft_parse_argument(char **argv, int argc, int *start);
bool	ft_isvalid(char *str);
bool	stk_contain_duplicates(t_stack *stack);
bool	ft_handle_argument(int argc, char **argv, t_stack *stack);
bool	ft_push_to_stack(char **arr, int argc, int count, t_stack *stack);

void	solution_complex(t_stack *stack_a, t_stack *stack_b, int size);
int		ft_bit_size(int value);

void	solution_two(t_stack *stack);
void	solution_three(t_stack *stack);
void	solution_four(t_stack *stack_a, t_stack *stack_b, int size);
void	solution_five(t_stack *stack_a, t_stack *stack_b, int size);

void	ft_stk_set_index(t_stack *stack, t_list *guide);
int		ft_stk_get_next(t_stack *stack);
int		ft_stk_get_size(t_stack *stack);
int		ft_stk_get_bottom(t_stack *stack);
bool	ft_is_exist(t_stack *stack, int value);

void	sort_stack(t_stack *stack_a, t_stack *stack_b);

void	swap(t_stack *stack);
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);

void	ft_error(void);
void	ft_stk_print(t_stack *stack);
bool	ft_exit(char **ptr);
bool	ft_stk_clear(t_stack *stack);
bool	ft_add_to_stack(char **arr, int count, t_stack *stack);

int		ft_wordcount(char const *s, char c);
char	**ft_get_numbers(char **argv, int *start);
bool	ft_pre_valid(char *str);

#endif

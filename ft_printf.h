/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 08:53:33 by tsomacha          #+#    #+#             */
/*   Updated: 2025/01/05 13:04:34 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <stdint.h>

# include "libft.h"

int		ft_printchar(int c);
int		ft_printstr(char *str);
int		ft_pointer(unsigned long nbr);
int		ft_printdigit(int c, int set_case);
int		ft_printpointer(unsigned long nbr);
int		ft_printf(const char *format, ...);
int		ft_printnbr_base(long nbr, int base, int set_case);

#endif

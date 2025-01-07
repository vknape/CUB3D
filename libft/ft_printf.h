/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: snijhuis <snijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/01 10:06:16 by snijhuis      #+#    #+#                 */
/*   Updated: 2024/04/04 13:15:35 by snijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int	ft_printf(const char *input, ...);
int	print_cases(char character, va_list ap);
int	print_char(int c);
int	print_str(char *str);
int	ft_putnbr(long n, char *base);
int	check_length(long n, int count);
int	print_adres(unsigned long long ptr);

#endif

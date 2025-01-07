/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_cases.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: snijhuis <snijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/07 11:33:01 by snijhuis      #+#    #+#                 */
/*   Updated: 2023/11/15 11:55:26 by snijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_cases(char character, va_list ap)
{
	int	count;

	count = 0;
	if (character == 'c')
		count = print_char(va_arg(ap, int));
	else if (character == 's')
		count = print_str(va_arg(ap, char *));
	else if (character == 'd')
		count = ft_putnbr(va_arg(ap, int), "0123456789");
	else if (character == 'x')
		count = ft_putnbr(va_arg(ap, unsigned int), "0123456789abcdef");
	else if (character == 'X')
		count = ft_putnbr(va_arg(ap, unsigned int), "0123456789ABCDEF");
	else if (character == 'i')
		count = ft_putnbr(va_arg(ap, int), "0123456789");
	else if (character == '%')
		count = print_char('%');
	else if (character == 'u')
		count = ft_putnbr(va_arg(ap, unsigned int), "0123456789");
	else if (character == 'p')
		count = print_adres(va_arg(ap, long long unsigned int));
	return (count);
}

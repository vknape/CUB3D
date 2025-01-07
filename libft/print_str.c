/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_str.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: snijhuis <snijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/07 11:31:31 by snijhuis      #+#    #+#                 */
/*   Updated: 2023/11/15 10:46:43 by snijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str(char *str)
{
	int	count;

	count = 0;
	if (str == NULL)
	{
		return (print_str("(null)"));
	}
	while (*str)
	{
		print_char((int)*str);
		str++;
		count++;
	}
	return (count);
}

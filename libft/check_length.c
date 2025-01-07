/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_length.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: snijhuis <snijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/07 11:32:32 by snijhuis      #+#    #+#                 */
/*   Updated: 2023/11/15 10:46:22 by snijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_length(long n, int count)
{
	int	length;

	length = 0;
	if (n == 0)
		return (1);
	if (count == 10)
	{
		while (n > 0)
		{
			n /= 10;
			length++;
		}
	}
	else
	{
		while (n > 0)
		{
			n /= 16;
			length++;
		}
	}
	return (length);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: snijhuis <snijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/07 11:31:59 by snijhuis      #+#    #+#                 */
/*   Updated: 2023/11/15 14:03:12 by snijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long n, char *base)
{
	int		count;
	int		o;
	int		c;
	char	min;
	int		mincount;

	min = '-';
	count = 0;
	mincount = 0;
	if (n < 0)
	{
		mincount += write(1, &min, 1);
		n = n * -1;
	}
	while (base[count])
		count++;
	o = check_length(n, count);
	if (n >= count)
		ft_putnbr(n / count, base);
	n = n % count;
	c = base[n];
	write(1, &c, 1);
	return (o + mincount);
}

// int	ft_putnbr(long n, char *base)
// {
// 	int		count;
// 	int		o;
// 	int		c;
// 	char	min;
// 	int		mincount;

// 	min = '-';
// 	count = 0;
// 	mincount = 0;
// 	if (n < 0)
// 	{
// 		mincount += write(1, &min, 1);
// 		n = n * -1;
// 	}
// 	count += mincount;
// 	while (base[count])
// 		count++;
// 	o = check_length(n, count);
// 	if (n >= count)
// 		ft_putnbr(n / count, base);
// 	n = n % count;
// 	c = base[n];
// 	write(1, &c, 1);
// 	return (o + mincount);
// }

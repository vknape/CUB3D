/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: snijhuis <snijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/16 13:05:11 by snijhuis      #+#    #+#                 */
/*   Updated: 2023/10/23 15:09:20 by snijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>
// #include <unistd.h>

// void ft_putnbr_fd(int n, int fd);

// int main (void)
// {
//     ft_putnbr_fd(-22, 1);
//     return (0);
// }

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		n = -n;
		write(fd, "-", 1);
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		c = '0' + (n % 10);
		write(fd, &c, 1);
	}
	else
	{
		c = '0' + n;
		write(fd, &c, 1);
	}
	return ;
}

// fd where you want to print the number.
// recurtion /10 % 10; als boven 10
// write onder 10;
// negatief positief maken
// min opschrijven als het negatief is.
//(stdout) is 1;
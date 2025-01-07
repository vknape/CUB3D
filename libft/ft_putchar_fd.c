/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putchar_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: snijhuis <snijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/13 13:08:50 by snijhuis      #+#    #+#                 */
/*   Updated: 2023/10/23 14:51:12 by snijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <unistd.h>

// void ft_putchar_fd(char c, int fd);

// int main (void)
// {

//     return (0);
// }

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

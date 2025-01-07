/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: snijhuis <snijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/13 14:00:31 by snijhuis      #+#    #+#                 */
/*   Updated: 2023/10/23 14:50:56 by snijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <unistd.h>

// void ft_putstr_fd(char *s, int fd);

// int main (void)
// {

//     return (0);
// }

void	ft_putstr_fd(char *s, int fd)
{
	int	length;

	length = ft_strlen(s);
	if (s)
		write(fd, s, length);
	return ;
}

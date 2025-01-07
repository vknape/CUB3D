/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putendl_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: snijhuis <snijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/16 14:34:55 by snijhuis      #+#    #+#                 */
/*   Updated: 2023/10/23 14:51:05 by snijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <unistd.h>

// void ft_putendl_fd(char *s, int fd);

// int main (void)
// {
//     char c[] = "rupsen";
//     ft_putendl_fd(c, 1);
//     return (0);
// }

void	ft_putendl_fd(char *s, int fd)
{
	char	c;

	c = '\n';
	write(fd, s, ft_strlen(s));
	write(fd, &c, 1);
	return ;
}

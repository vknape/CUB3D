/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: snijhuis <snijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/08 15:37:10 by snijhuis      #+#    #+#                 */
/*   Updated: 2023/10/23 14:55:17 by snijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>
// #include <string.h>

// void ft_bzero(void *s, size_t n);

// int main (void)
// {
//     char a[] = "Ik ben een rups";
//     char b[] = "Ik ben een rups";
//     bzero(a, 5);
//     ft_bzero(b, 5);
//     printf("%s\n", a);
//     printf("%s", b);
//     return (0);
// }    

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*temp;

	temp = (unsigned char *)s;
	while (n > 0)
	{
		*temp = 0;
		n--;
		temp++;
	}
	return ;
}

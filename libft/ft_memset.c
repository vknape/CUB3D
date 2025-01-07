/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: snijhuis <snijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/06 15:50:43 by snijhuis      #+#    #+#                 */
/*   Updated: 2023/10/23 14:51:27 by snijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>

// void *ft_memset(void *s, int c, size_t n);

// int main (void)
// {
//     char c[50] = "ik ben een rups";
//     printf("%s", (char *) ft_memset(c, 'a', 5));
//     return (0);
// }

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*temp;

	temp = (unsigned char *)s;
	while (n > 0)
	{
		*temp = c;
		n--;
		temp++;
	}
	return (s);
}

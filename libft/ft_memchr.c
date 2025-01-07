/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: snijhuis <snijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/10 10:48:23 by snijhuis      #+#    #+#                 */
/*   Updated: 2023/10/23 14:52:25 by snijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>
// #include <string.h>

// void *ft_memchr(const void *s, int c, size_t n);

// int main (void)
// {
//     char str[50] = "ikbeneenrups.nl";
//     char search = 'b';
//     char *output = memchr(str, search, 16);
//     printf("%s\n", output);
//     char *output1 = ft_memchr(str, search, 16);
//     printf("%s\n", output1);
//     return (0);
// }

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	d;

	ptr = (unsigned char *)s;
	d = (unsigned char) c;
	while (n > 0)
	{
		if (*ptr == d)
		{
			return ((void *)ptr);
		}
		ptr++;
		n--;
	}
	return (0);
}

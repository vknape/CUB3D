/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: snijhuis <snijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/10 11:46:36 by snijhuis      #+#    #+#                 */
/*   Updated: 2023/10/23 14:52:07 by snijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>
// #include <string.h>

// int ft_memcmp(const void *s1, const void *s2, size_t n);

// int main (void)
// {
//     char str1[] = "AAAAAAA";
//     char str2[] = "AAAAAAA";
//     int output = memcmp(str1, str2, 23);
//     int output1 = ft_memcmp(str1, str2, 23);
//     printf("%d\n", output);
//     printf("%d\n", output1);
//     return (0);
// }

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
		i++;
	}
	return (0);
}

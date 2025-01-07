/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: snijhuis <snijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/08 12:46:08 by snijhuis      #+#    #+#                 */
/*   Updated: 2023/10/23 14:48:57 by snijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <bsd/string.h>
// #include <stdio.h>

// int ft_strlcpy(char *dst, const char *src, size_t size);

// int main (void)
// {
//     char dst[] = "Ik ben een";
//     char src[] = "rups.";
//     char dst1[] = "Ik ben een";
//     char src1[] = "rups.";
//     printf("%ld\n", strlcpy(dst1, src1, 20));
//     printf("%s\n", dst1);
//     printf("%d\n", ft_strlcpy(dst, src, 20));
//     printf("%s", dst);
//     return (0);
// }

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	index;

	index = 0;
	if (size == 0)
	{
		return (ft_strlen(src));
	}
	while (src[index] && index < size - 1)
	{
		dst[index] = src[index];
		index++;
	}
	dst[index] = '\0';
	return (ft_strlen(src));
}

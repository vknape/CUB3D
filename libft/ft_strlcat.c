/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: snijhuis <snijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/09 12:38:15 by snijhuis      #+#    #+#                 */
/*   Updated: 2023/11/16 14:06:20 by snijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <bsd/string.h>
// #include <stdio.h>

// size_t ft_strlcat(char *dst, const char *src, size_t size);

// int main (void)
// {
//     char src[]= " rups";
//     char dst[40]= "Ik ben een";
//     char src1[]= " rups";
//     char dst1[40]= "Ik ben een";

//     printf ("%ld\n", strlcat(dst, src, 0));
//     printf ("%s\n", dst);
//       printf ("%ld\n", ft_strlcat(dst1, src1, 0));
//     printf ("%s", dst1);
//     return (0);
// }

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int		count;
	size_t	i;
	char	*dst1;

	count = ft_strlen(dst) + ft_strlen(src);
	dst1 = dst;
	i = 0;
	if (ft_strlen(dst) >= size)
		return (size + ft_strlen(src));
	while (*dst && size > i)
	{
		dst++;
		i++;
	}
	while (*src && size - 1 > i)
	{
		*dst = *src;
		dst++;
		src++;
		i++;
	}
	*dst = '\0';
	return (count);
}

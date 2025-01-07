/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: snijhuis <snijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/09 14:40:39 by snijhuis      #+#    #+#                 */
/*   Updated: 2023/10/23 14:51:31 by snijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>
// #include <string.h>

// void	*ft_memmove(void *dest, const void *src, size_t n);

// int	main(void)
// {
// 	char	dest1[50] = "abcdefgij";
// 	char	src1[50] = "123456789";
//     char	dest[50] = "abcdefgij";
// 	char	src[50] = "123456789";

//     memmove(dest1, src1, 22);
// 	printf("%s\n", dest1);
// 	ft_memmove(dest, src, 22);
// 	printf("%s", dest);
// 	return (0);
// }

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*temp_dest;
	const char	*temp_src;
	size_t		i;

	temp_src = (const char *)src;
	temp_dest = (char *)dest;
	i = 0;
	if (dest > src)
	{
		while (n > 0)
		{
			temp_dest[n - 1] = temp_src[n - 1];
			n--;
		}
	}
	if (dest < src)
	{
		while (i < n)
		{
			temp_dest[i] = temp_src[i];
			i++;
		}
	}
	return (dest);
}

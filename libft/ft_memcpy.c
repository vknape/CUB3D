/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: snijhuis <snijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/08 16:16:58 by snijhuis      #+#    #+#                 */
/*   Updated: 2023/10/23 15:06:22 by snijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>
// #include <string.h>

// void *ft_memcpy(void *dest, const void *src, size_t n);

// int main (void)
// {
//     char src[] =  "Copy this";
//     char dest[100];

//     ft_memcpy(dest, src, strlen(src) + 1);

//     printf("%s\n", dest);
//     return (0);
// }

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*dest_edit;
	const char	*src_edit;

	i = 0;
	dest_edit = (char *)dest;
	src_edit = (const char *)src;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (i < n)
	{
		dest_edit[i] = src_edit[i];
		i++;
	}
	return (dest);
}

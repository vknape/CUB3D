/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: snijhuis <snijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/06 10:09:32 by snijhuis      #+#    #+#                 */
/*   Updated: 2023/10/23 14:48:37 by snijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>
// #include <string.h>

// int ft_strncmp (const char *a, const char *b, size_t size);

// int main (void)
// {
//     char    a[]  = "ab";
//     char    b[] = "ab";
//     int size;
//     size = 10;
//     printf("%d\n", strncmp(a, b, size));
//     printf("%d", ft_strncmp(a, b, size));
//     return (0);
// }

int	ft_strncmp(const char *a, const char *b, size_t size)
{
	size_t	i;

	i = 0;
	while (i != size)
	{
		if (a[i] != b[i] || a[i] == '\0' || b[i] == '\0')
			return ((unsigned char)a[i] - (unsigned char)b[i]);
		i++;
	}
	return (0);
}

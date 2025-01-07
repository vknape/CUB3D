/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: snijhuis <snijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/10 13:33:33 by snijhuis      #+#    #+#                 */
/*   Updated: 2023/10/23 14:48:11 by snijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <bsd/string.h>
// #include <stdio.h>

// char *ft_strnstr(const char *big, const char *little, size_t len);

// int main (void)
// {
//     char str1[50] = "Wij zruoeken aaahp up rup rjpsen.";
//     char str2[50] = "aah";
//     printf("%s\n", strnstr(str1, str2, 50));
//     printf("%s", ft_strnstr(str1, str2, 50));
//     return (0);
// }

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i1;
	size_t	i2;

	i1 = 0;
	i2 = 0;
	if (*little == '\0')
		return ((char *)big);
	while (big[i1] != '\0' && i1 < len)
	{
		i2 = 0;
		while (big[i1] == little[i2] && i1 < len)
		{
			if (little[i2 + 1] == '\0')
			{
				return ((char *)big + i1 - i2);
			}
			i1++;
			i2++;
		}
		i1 = i1 - i2;
		i1++;
	}
	return (0);
}

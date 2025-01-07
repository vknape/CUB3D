/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: snijhuis <snijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/06 13:01:53 by snijhuis      #+#    #+#                 */
/*   Updated: 2023/10/23 14:50:33 by snijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>
// #include <string.h>

// char *ft_strchr(const char *str, int c);

// int main (void)
// {
//     const char str[] = "Ik ben een rups";
//     const char ch = 'i';

//     printf ("%s\n", ft_strchr(str, ch));
//     printf ("%s", strchr(str, ch));
//     return (0);
// }

char	*ft_strchr(const char *str, int c)
{
	int	i;

	c = c % 256;
	i = 0;
	if (c > 127)
		return ((char *)str);
	while (str[i] != '\0')
	{
		if (str[i] == c)
		{
			return ((char *)str + i);
		}
		i++;
	}
	if (c == '\0')
		return ((char *)str + i);
	return (0);
}

//\null turminator ook vinden
// return NULL bij niet gevonden
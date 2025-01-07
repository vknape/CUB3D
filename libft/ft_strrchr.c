/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: snijhuis <snijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/06 14:17:47 by snijhuis      #+#    #+#                 */
/*   Updated: 2023/10/23 14:48:15 by snijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char *ft_strrchr (const char *str, int c);

// int main (void)
// {
//     printf ("%s\n", strrchr("rups rups", 'r'));
//     printf ("%s", ft_strrchr("rups rups", 'r'));
//     return (0);
// }

char	*ft_strrchr(const char *str, int c)
{
	int	index;

	c = c % 256;
	index = 0;
	if (c > 127 || c < 0)
		return ((char *)str);
	while (*str)
	{
		index++;
		str++;
	}
	while (index >= 0)
	{
		if (*str == c)
			return ((char *)str);
		index--;
		str--;
	}
	return (NULL);
}

// returns a pointer to the last occurrence of the character c in str
/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: snijhuis <snijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 13:22:30 by snijhuis      #+#    #+#                 */
/*   Updated: 2023/10/21 17:36:14 by snijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>
// int ft_strlen (char* c);

// int main (void)
// {
//     char c[] = "rghups";
//     printf("%d", ft_strlen(c));
//     return (0);
// }

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

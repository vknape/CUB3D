/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: snijhuis <snijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/15 15:40:02 by snijhuis      #+#    #+#                 */
/*   Updated: 2023/10/23 14:48:48 by snijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>
// #include <stdlib.h>

// char *ft_strmapi(char const *s, char (*f)(unsigned int, char));
// char functienaam (unsigned int index, char c);

// int main (void)
// {
//     char *string = "abcdefg";
//     char *result = ft_strmapi(string, functienaam);
//     printf("%s", result);
//     return (0);
// }

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		length;
	char	*str;
	int		i;

	length = ft_strlen(s);
	str = malloc(length + 1);
	i = 0;
	if (!str)
		return (NULL);
	while (s[i] != '\0')
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

// char functienaam (unsigned int index, char c)
// {
//     if (index % 2 == 0)
//     return (c -1);
//     else
//     return (c +1);
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: snijhuis <snijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/12 11:24:47 by snijhuis      #+#    #+#                 */
/*   Updated: 2024/05/13 16:02:09 by snijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>
// #include <stdlib.h>

// char *ft_strjoin(char const *s1, char const *s2);

// int main (void)
// {
//     char str1[] = "un";
//     char str2[] = "happy";
//     printf("%s", ft_strjoin(str1, str2));
//     return (0);
// }



char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*newstring;

	i = 0;
	newstring = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (newstring == NULL)
		return (NULL);
	while (*s1)
	{
		newstring[i] = *s1;
		i++;
		s1++;
	}
	while (*s2)
	{
		newstring[i] = *s2;
		i++;
		s2++;
	}
	newstring[i] = '\0';
	return (newstring);
}

// return NULL if there is a problem with memory
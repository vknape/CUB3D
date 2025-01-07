/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: snijhuis <snijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/11 15:05:16 by snijhuis      #+#    #+#                 */
/*   Updated: 2023/10/23 15:05:57 by snijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char *ft_strdup(const char *s);
// int main (void)
// {
//     char *van = "Rupsen gedrag";
//     char *naar;
//     char *van1 = "Rupsen gedrag";
//     char *naar1;
//     naar = strdup(van);
//     naar1 = ft_strdup(van1);
//     printf("%p\n", naar);
//     printf("%p\n", naar1);
//     return (0);
// }

char	*ft_strdup(const char *s)
{
	char	*adres;
	size_t	i;
	char	*result;

	i = ft_strlen(s);
	adres = malloc(i + 1);
	if (adres == NULL)
		return (NULL);
	result = adres;
	while (*s)
	{
		*adres = *s;
		s++;
		adres++;
	}
	*adres = '\0';
	return (result);
}

// pointer to a null terminated new string
// returns a pointer to the location of the duplicate of string s

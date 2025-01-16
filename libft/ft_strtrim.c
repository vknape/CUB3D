/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vknape <vknape@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 11:51:55 by snijhuis          #+#    #+#             */
/*   Updated: 2025/01/16 13:07:19 by vknape           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char *ft_strtrim(char const *s1, char const *set);

// int main (void)
// {
//     const char * str = "oosoRupsenooo";
//     const char * zoek = "o";
//     printf("%s", ft_strtrim(str, zoek));
//     return (0);
// }

char	*ft_strtrim(char const *s1, char const *set)
{
	const char	*end;
	size_t		length;
	char		*trim;

	end = s1 + ft_strlen(s1) - 1;
	while (*s1 && ft_strchr(set, *s1))
	{
		s1++;
	}
	while (end > s1 && ft_strchr(set, *end))
	{
		end--;
	}
	length = end - s1 + 1;
	trim = malloc(length + 1);
	if (trim == NULL)
		return (NULL);
	ft_strlcpy(trim, s1, length + 1);
	return (trim);
}

// NULL returnen al malloc niet werkt

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: snijhuis <snijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/11 16:22:01 by snijhuis      #+#    #+#                 */
/*   Updated: 2023/10/23 14:48:18 by snijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	length;
	char	*c;

	i = 0;
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (ft_strlen(s) - start < len)
		length = ft_strlen(s) - start;
	else
		length = len;
	c = malloc(length + 1 * sizeof(char));
	if (c == NULL)
		return (NULL);
	while (i < len && s[start + i])
	{
		c[i] = s[start + i];
		i++;
	}
	c[i] = '\0';
	return (c);
}

// int main () {
// 	char c[50] = "yipl.hotmail.com";
// 	printf("%s", ft_substr(c, 5, 30));
// }

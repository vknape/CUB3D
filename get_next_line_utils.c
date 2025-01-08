/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vknape <vknape@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:57:46 by vknape            #+#    #+#             */
/*   Updated: 2023/11/30 09:09:42 by vknape           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *c)
{
	int	i;

	i = 0;
	if (!c)
		return (0);
	while (c[i])
		i++;
	return (i);
}

int	ft_strlcpy(char *dst, const char *src, size_t size)
{
	int	i;

	i = 0;
	while (src[i])
		i++;
	if (*src == 0)
	{
		*dst = '\0';
		return (0);
	}
	if (size == 0)
		return (i);
	while (*src != '\0' && size > 1)
	{
		*dst = *src;
		dst++;
		src++;
		size--;
	}
	*dst = '\0';
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	int		i;

	i = 0;
	if (s1)
		i = ft_strlen(s1);
	new = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (new == NULL)
		return (free_all(&s1));
	if (s1)
		ft_strlcpy(new, s1, ft_strlen(s1) + 1);
	ft_strlcpy(&new[i], s2, ft_strlen(s2) + 1);
	free_all(&s1);
	return (new);
}

int	ft_strchr(const char *s, int c)
{
	unsigned int	i;

	i = 0;
	c = c % 256;
	if (!s)
		return (-1);
	while (s[i] != c)
	{
		if (!s[i])
			return (-1);
		i++;
	}
	return (i);
}

char	*free_all(char **s)
{
	free(*s);
	*s = NULL;
	return (NULL);
}

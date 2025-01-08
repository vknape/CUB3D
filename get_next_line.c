/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vknape <vknape@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:57:19 by vknape            #+#    #+#             */
/*   Updated: 2023/11/30 08:57:15 by vknape           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(int fd, char *rest, int chars, char *buffer);
char	*make_line(char *rest);
char	*move_buffer(char *rest);

char	*get_next_line(int fd)
{
	static char		*array;
	char			*buffer;
	char			*line;
	int				chars;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = NULL;
	chars = BUFFER_SIZE;
	array = read_line(fd, array, chars, buffer);
	if (!array)
		return (NULL);
	line = make_line(array);
	if (!line)
		return (free_all(&array));
	array = move_buffer(array);
	return (line);
}

char	*read_line(int fd, char *rest, int chars, char *buffer)
{
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (free_all(&rest));
	while (chars > 0)
	{
		chars = read(fd, buffer, BUFFER_SIZE);
		if (chars == -1)
		{
			free_all(&rest);
			return (free_all(&buffer));
		}
		buffer[chars] = '\0';
		rest = ft_strjoin(rest, buffer);
		if (!rest)
			return (free_all(&buffer));
		if (ft_strchr(buffer, '\n') > -1)
			break ;
	}
	free_all(&buffer);
	return (rest);
}

char	*make_line(char *rest)
{
	char	*line;
	int		i;
	int		len;

	if (!rest[0])
		return (NULL);
	len = ft_strlen(rest);
	i = ft_strchr(rest, '\n') + 1;
	if (ft_strchr(rest, '\n') < 0)
		i = len;
	line = malloc((i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	ft_strlcpy(line, rest, i + 1);
	return (line);
}

char	*move_buffer(char *rest)
{
	char	*buffer;
	int		i;
	int		len;

	buffer = NULL;
	if (!rest[0])
		return (free_all(&rest));
	len = ft_strlen(rest);
	i = ft_strchr(rest, '\n') + 1;
	if (ft_strchr(rest, '\n') < 0)
		i = len;
	buffer = ft_strjoin(buffer, rest + i);
	free_all(&rest);
	return (buffer);
}

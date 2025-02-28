/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: vknape <vknape@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/06 10:57:49 by vknape        #+#    #+#                 */
/*   Updated: 2025/01/09 13:33:39 by snijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# ifdef BUFFER_SIZE
#  if BUFFER_SIZE < 0
#   undef BUFFER_SIZE
#   define BUFFER_SIZE 1
#  endif
#  if BUFFER_SIZE > INT_MAX
#   undef BUFFER_SIZE
#   define BUFFER_SIZE 1
#  endif
# endif
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
char	*ft_strjoin_gnl(char *s1, char *s2);
int		ft_strchr_gnl(const char *s, int c);
int		ft_strlcpy_gnl(char *dst, const char *src, size_t size);
size_t	ft_strlen_gnl(const char *c);
char	*free_all(char **s);

#endif
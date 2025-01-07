/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: snijhuis <snijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/12 16:44:27 by snijhuis      #+#    #+#                 */
/*   Updated: 2024/01/24 14:34:12 by snijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char		**ft_split(char const *s, char c);
static int	count_words(const char *s, char c);
static char	**ft_free(int i, char **ptr);
static char	*malloc_word(const char **s, char c);

// int main (void)
// {
//     char **test = ft_split("sed 's/And/But/'", ' ');
//     int i = 0;
//     while (test[i])
//     {
//         printf("%s\n", test[i]);
//         i ++;
//     }
//     return (0);
// }

static int	count_words(const char *s, char c)
{
	int	counter;

	counter = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			counter++;
		while (*s && *s != c)
			s++;
	}
	return (counter);
}

static char	**ft_free(int i, char **ptr)
{
	while (i >= 0)
	{
		free(ptr[i]);
		i--;
	}
	return (NULL);
}

static char	*malloc_word(const char **s, char c)
{
	const char	*start;
	char		*word;

	while (**s == c)
		(*s)++;
	start = *s;
	while (**s && **s != c)
		(*s)++;
	word = malloc((*s - start) + 1);
	if (word)
		ft_strlcpy(word, start, (*s - start) + 1);
	return (word);
}

char	**ft_split(char const *s, char c)
{
	int		words;
	char	**ptr;
	int		i;

	words = count_words(s, c);
	ptr = malloc((words + 1) * sizeof(char *));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < words)
	{
		ptr[i] = malloc_word(&s, c);
		if (ptr[i] == NULL)
			return (ft_free(i, ptr));
		i++;
	}
	ptr[i] = NULL;
	return (ptr);
}

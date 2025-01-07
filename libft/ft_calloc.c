/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: snijhuis <snijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/11 13:41:49 by snijhuis      #+#    #+#                 */
/*   Updated: 2025/01/07 13:56:32 by snijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>
// #include <stdlib.h>

// void *ft_calloc(size_t nmemb, size_t size);

// int main (void)
// {
//     calloc(100, sizeof(int));
//     ft_calloc(100, sizeof(int));
//     return (0);
// }

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	calc;
	void	*adres;

	if ((size > 2147483647 && nmemb > 0) || (nmemb > 2147483647 && size > 0))
		return (NULL);
	if (nmemb * size > 2147483647)
		return (NULL);
	calc = nmemb * size;
	adres = malloc(calc);
	if (adres == NULL)
		return (NULL);
	ft_bzero(adres, calc);
	return (adres);
}

// if adres == NULL return NULL

// malloc doesnts set memory to zero but calloc sets it to zero

// size die je wilt hebben voor malloc berekenen
// pointer naar het begin adres van malloc
// bezoro gebruiken op de totale malloc grote

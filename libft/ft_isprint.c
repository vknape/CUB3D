/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isprint.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: snijhuis <snijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 13:14:55 by snijhuis      #+#    #+#                 */
/*   Updated: 2023/10/23 14:53:31 by snijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>

// int ft_isprint (char c);

// int main (void)
// {
//     char c = 'a';
//     printf("%d", ft_isprint(c));
//     return (0);
// }

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}

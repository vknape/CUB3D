/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalpha.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: snijhuis <snijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/02 13:14:21 by snijhuis      #+#    #+#                 */
/*   Updated: 2023/10/23 14:54:00 by snijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>

// int ft_isalpha (char c);

// int main (void)
// {
//     char c = '^';
//     ft_isalpha (c);
//     printf("%d", ft_isalpha(c));
//     return (0);
// }

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	else
		return (0);
}

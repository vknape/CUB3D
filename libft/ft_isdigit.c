/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isdigit.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: snijhuis <snijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/02 14:40:08 by snijhuis      #+#    #+#                 */
/*   Updated: 2023/10/23 14:53:42 by snijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>

// int ft_isdigit (char c);

// int main (void)
// {
//     char c = '1';
//     printf("%d", ft_isdigit(c));
//     return (0);
// }

int	ft_isdigit(int c)
{
	if ((c >= 48 && c <= 57))
		return (1);
	else
		return (0);
}

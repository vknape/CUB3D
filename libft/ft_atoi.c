/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: snijhuis <snijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/11 11:03:24 by snijhuis      #+#    #+#                 */
/*   Updated: 2024/03/07 12:52:17 by snijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// int ft_atoi(const char *nptr);

// int main (void)
// {
//     char str1[20] = "+-42";
//     char str2[20] = "+-42";
//     printf("%d\n", atoi(str1));
//     printf("%d", ft_atoi(str2));
//     return (0);
// }

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	n;

	sign = 1;
	n = 0;
	while ((*nptr == 32) || (*nptr >= 9 && *nptr <= 13))
	{
		nptr++;
	}
	if (*nptr == '+')
	{
		nptr++;
	}
	else if (*nptr == '-')
	{
		sign *= -1;
		nptr++;
	}
	while (*nptr >= 48 && *nptr <= 57)
	{
		n = n * 10 + *nptr - '0';
		nptr++;
	}
	return (n * sign);
}

// minnen tellen
// een plus
// min plus werkt niet

// spaties voor min wel spatie erna gaat gewoonn tot dan

// white spaces voor het beginnen skippen

// 9 tm 13 en 32

// edgecase grootste int behandelen

// int ft_atoi(const char *nptr)
// {
//     int sign = 1;
//     int n = 0;

//     while ((*nptr == 32)  || (*nptr >= 9 && *nptr <= 13))
//     {
//         nptr ++;
//     }
//     if (*nptr == '+')
//     {
//         nptr ++;
//     }
//     if (*nptr == '-')
//     {
//         sign *= -1;
//         nptr ++;
//     }

//     while (*nptr >= 48 && *nptr <= 57)
//     {
//         n = n * 10 + *nptr - '0';
//         nptr ++;
//     }
//     return (n * sign);
// }

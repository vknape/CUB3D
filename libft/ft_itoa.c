/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: snijhuis <snijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/13 13:42:13 by snijhuis      #+#    #+#                 */
/*   Updated: 2023/10/23 14:52:34 by snijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>
// #include <stdlib.h>

// char *ft_itoa(int n);

// int main (void)
// {
//     printf("%s", ft_itoa(-123));
//     return (0);
// }

static int	ft_special(int *n)
{
	if (*n == 0)
		return (1);
	if (*n == -2147483648)
		return (2);
	if (*n < 0)
		return (3);
	return (0);
}

static int	ft_length(int n)
{
	int	len;

	len = 0;
	if (n < 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	int		sign;
	char	*str;

	sign = ft_special(&n);
	if (sign == 1)
		return (ft_strdup("0"));
	if (sign == 2)
		return (ft_strdup("-2147483648"));
	len = ft_length(n);
	str = malloc(len + 1);
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	if (sign == 3)
	{
		str[0] = '-';
		n = -n;
	}
	while (n != 0)
	{
		str[--len] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}

// char	*ft_itoa(int n)
// {
// 	int		len;
// 	int		sign;
// 	int		temp;
// 	char	*str;

// 	sign = 1;
// 	len = 0;
// 	if (n == 0)
// 		return (ft_strdup("0"));
// 	if (n == -2147483648)
// 		return (ft_strdup("-2147483648"));
// 	if (n < 0)
// 	{
// 		len++;
// 		sign = -1;
// 		n = -n;
// 	}
// 	temp = n;
// 	while (temp > 0)
// 	{
// 		temp /= 10;
// 		len++;
// 	}
// 	str = malloc(len + 1);
// 	if (str == NULL)
// 		return (NULL);
// 	str[len] = '\0';
// 	if (sign == -1)
// 		str[0] = '-';
// 	while (n != 0)
// 	{
// 		len--;
// 		str[len] = (n % 10) + '0';
// 		n /= 10;
// 	}
// 	return (str);
// }

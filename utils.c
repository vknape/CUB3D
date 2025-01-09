/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: snijhuis <snijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/09 13:00:10 by snijhuis      #+#    #+#                 */
/*   Updated: 2025/01/09 15:35:21 by snijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	custom_strlen(char *str)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		if (ft_isprint(str[i]))
			count = i;
		i++;
	}
	return (count + 1);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: snijhuis <snijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/07 13:11:12 by snijhuis      #+#    #+#                 */
/*   Updated: 2025/01/09 15:35:32 by snijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_struct(t_all **all)
{
	(*all) = ft_calloc(1, sizeof(t_all));
	if (!(*all))
		exit(-1);
	(*all)->parse = ft_calloc(1, sizeof(t_parse));
	if (!(*all)->parse)
		clean_all((*all), 0);
	(*all)->game = ft_calloc(1, sizeof(t_parse));
	if (!(*all)->game)
		clean_all((*all), 0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vknape <vknape@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:11:12 by snijhuis          #+#    #+#             */
/*   Updated: 2025/01/28 14:16:10 by vknape           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

//Allocates memory and sets everything to 0

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
	(*all)->ray = ft_calloc(1, sizeof(t_ray));
	if (!(*all)->ray)
		clean_all((*all), 0);
}
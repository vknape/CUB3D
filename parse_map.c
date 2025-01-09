/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: snijhuis <snijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/09 15:10:36 by snijhuis      #+#    #+#                 */
/*   Updated: 2025/01/09 15:35:27 by snijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	parse_map(t_all *all)
{
	int i;

	// check end of 2darray doesn't segfault
	all->parse->map = ft_calloc(all->parse->map_height + 1, sizeof(char *));
	if (!all->parse->map)
		clean_all(all, 1);
	i = 0;
	while (i < all->parse->map_height)
	{
		all->parse->map[i] = ft_calloc(all->parse->map_width + 1, sizeof(char));
		if (!all->parse->map[i])
			clean_all(all, 1);
		i++;
	}
	return ;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vknape <vknape@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:25:38 by snijhuis          #+#    #+#             */
/*   Updated: 2025/01/16 13:10:06 by vknape           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

//Main function for cleaning and exiting the program

void	clean_all(t_all *all, int status)
{
	printf("map height %d\n", all->parse->map_height);
	printf("map width: %d\n", all->parse->map_width);

	clean_parse(all);
	if (all->game)
		free(all->game);
	if (all)
		free(all);
	printf("exit %d\n", status);
	exit(status);
}

void	clean_parse(t_all *all)
{
	int	i;

	i = -1;
	empty_buffer(all);
	if (all->parse->north)
		free(all->parse->north);
	if (all->parse->south)
		free(all->parse->south);
	if (all->parse->west)
		free(all->parse->west);
	if (all->parse->east)
		free(all->parse->east);
	if (all->parse->floor)
		free(all->parse->floor);
	if (all->parse->ceiling)
		free(all->parse->ceiling);
	while (all->parse->map && all->parse->map[++i])
		free(all->parse->map[i]);
	if (all->parse->map)
		free(all->parse->map);
	if (all->parse)
		free(all->parse);
}

void	empty_buffer(t_all *all)
{
	if (all->parse->line)
		free(all->parse->line);
	if (all->parse->fd_cub)
	{
		all->parse->line = get_next_line(all->parse->fd_cub);
		while (all->parse->line)
		{
			free(all->parse->line);
			all->parse->line = get_next_line(all->parse->fd_cub);
		}
		close(all->parse->fd_cub);
	}
}

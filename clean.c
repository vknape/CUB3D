/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   clean.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: vknape <vknape@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/07 14:25:38 by snijhuis      #+#    #+#                 */
/*   Updated: 2025/02/24 11:40:25 by snijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// Main function for cleaning and exiting the program

void	clean_all(t_all *all, int status)
{
	if (all->parse)
		clean_parse(all);
	if (all->texture)
		clean_texture(all);
	if (all->game)
		clean_game(all);
	if (all->ray)
		free(all->ray);
	if (all)
		free(all);
	exit(status);
}

void	clean_game(t_all *all)
{
	if(all->game->window)
		mlx_terminate(all->game->window);
	if(all->game->image)
		mlx_delete_image(all->game->window, all->game->image);
	free(all->game);
}

void	clean_texture(t_all *all)
{
	if(all->texture->north)
		mlx_delete_texture(all->texture->north);
	if(all->texture->south)
		mlx_delete_texture(all->texture->south);
	if(all->texture->east)
		mlx_delete_texture(all->texture->east);
	if(all->texture->west)
		mlx_delete_texture(all->texture->west);
	free(all->texture);
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

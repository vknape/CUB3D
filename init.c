/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: vknape <vknape@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/07 13:11:12 by snijhuis      #+#    #+#                 */
/*   Updated: 2025/02/11 14:03:53 by snijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// Allocates memory and sets everything to 0

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
	(*all)->texture = ft_calloc(1, sizeof(t_ray));
	if (!(*all)->texture)
		clean_all((*all), 0);
}

void	load_textures(t_all *all)
{
	all->parse->north = ft_strtrim(all->parse->north, "\n");
	all->parse->south = ft_strtrim(all->parse->south, "\n");
	all->parse->east = ft_strtrim(all->parse->east, "\n");
	all->parse->west = ft_strtrim(all->parse->west, "\n");
	// all->parse->north[ft_strlen(all->parse->north)] = '\0';
	// printf("north: %s\n", all->parse->north + 3);
	// printf("north: %c\n", all->parse->north[ft_strlen(all->parse->north)]);
	all->texture->north = mlx_load_png(all->parse->north + 3);
	if (!all->texture->north) // we dont clean the texture yet in clean all
		clean_all(all, 20);
	all->texture->south = mlx_load_png(all->parse->south + 3);
	if (!all->texture->south) // we dont clean the texture yet in clean all
		clean_all(all, 16);
	all->texture->east = mlx_load_png(all->parse->east + 3);
	if (!all->texture->east) // we dont clean the texture yet in clean all
		clean_all(all, 17);
	all->texture->west = mlx_load_png(all->parse->west + 3);
	if (!all->texture->west) // we dont clean the texture yet in clean all
		clean_all(all, 18);
	scale_texture(all);
	// all->game->north = mlx_load_png("./rups.png");
	// all->game->image = mlx_texture_to_image(all->game->window, all->game->north);
	// mlx_image_to_window(all->game->window, all->game->image, 0, 0);
	// mlx_set_instance_depth(all->game->image->instances, 0);
}

void	scale_texture(t_all *all)
{
	all->texture->north_scale_h = all->texture->north->height / BLOCK;
	all->texture->north_scale_w = all->texture->north->width / BLOCK;

	all->texture->south_scale_h = all->texture->south->height / BLOCK;
	all->texture->south_scale_w = all->texture->south->width / BLOCK;

	all->texture->east_scale_h = all->texture->east->height / BLOCK;
	all->texture->east_scale_w = all->texture->east->width / BLOCK;

	all->texture->west_scale_h = all->texture->west->height / BLOCK;
	all->texture->west_scale_w = all->texture->west->width / BLOCK;
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   put_pixel.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: vknape <vknape@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/21 13:24:06 by snijhuis      #+#    #+#                 */
/*   Updated: 2025/02/25 16:21:40 by snijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	print_mini_map(t_all *all, int i, int j, int offset_i, int offset_j)
{
	int			x;
	int			y;
	uint32_t	color;

	color = color_mini(all, i, j, offset_i, offset_j);
	x = 0;
	y = 0;
	while (y < MINI_BLOCK)
	{
		while (x < MINI_BLOCK)
		{
			mlx_put_pixel(all->game->image, i * MINI_BLOCK + x, j * MINI_BLOCK + y,
				color);
			x++;
		}
		x = 0;
		y++;
	}
	print_player(all);
}

uint32_t	color_mini(t_all *all, int i, int j, int offset_i, int offset_j)
{
	uint32_t	color;

	color = 0;
	i += offset_i;
	j += offset_j;
	// if (floor(all->game->px) > MINI_LIMITS)
	// 	i = floor(all->game->px) - MINI_LIMITS;
	// if (floor(all->game->py) > MINI_LIMITS)
	// 	j = floor(all->game->py) - MINI_LIMITS;
	// if (i > all->parse->map_width)
	// 	i = all->parse->map_width -1;
	// if (j > all->parse->map_height)
	// 	j = all->parse->map_height - 1;
	if (i >= all->parse->map_width || j >= all->parse->map_height)
		color = 0x000000FF;
	else if (all->parse->map[j][i] == space)
		color = 0x000000FF;
	else if (all->parse->map[j][i] == ground)
		color = 0xFFFFFFFF;
	else if (all->parse->map[j][i] == wall)
		color = 0x000000FF;
	else
		color = 0xFF0000FF;
	return (color);
}

void print_player(t_all *all)
{
	int i;
	int j;
	
	i = 0;
	j = 0;
	while (j < 16)
	{
		while (i < 16)
		{
			mlx_put_pixel(all->game->image, all->game->px * MINI_BLOCK + i - 8,
				all->game->py * MINI_BLOCK + j - 8, 0xFF0000FF);
			i++;
		}
		i = 0;
		j++;
	}
}

void	print_background(t_all *all)
{
	int			x;
	int			y;
	uint32_t	color;

	x = 0;
	y = 0;
	while (y < WINDOW_Y)
	{
		if (y < WINDOW_Y / 2)
			color = 0xFFFFFFFF;
		else
			color = 0x000000FF;
		while (x < WINDOW_X)
		{
			mlx_put_pixel(all->game->image, x, y, color);
			x++;
		}
		x = 0;
		y++;
	}
}

void	ft_print(void *param)
{
	t_all	*all;
	int		i;
	int		j;
	int		offset_i;
	int		offset_j;

	all = param;
	print_background(all);
	ft_raydir(all);
	i = 0;
	j = 0;
	offset_i = 0;
	offset_j = 0;
	if (floor(all->game->px) >= MINI_LIMITS)
		offset_i = floor(all->game->px) - MINI_LIMITS;
	if (offset_i + 2 * MINI_LIMITS >= all->parse->map_width)
		offset_i = all->parse->map_width - 1 - 2 * MINI_LIMITS;
	if (floor(all->game->py) >= MINI_LIMITS)
		offset_j = floor(all->game->py) - MINI_LIMITS;
	if (offset_j + 2 * MINI_LIMITS >= all->parse->map_height)
		offset_j = all->parse->map_height - 1 - 2 * MINI_LIMITS;
	while (j < MINI_LIMITS * 2)
	{
		while (i < MINI_LIMITS * 2)
		{
			print_mini_map(all, i, j, offset_i, offset_j);
			i++;
		}
		i = 0;
		j++;
	}
}

// for minimap player drawing:
// i = 0;
// j = 0;
// while (j < 24)
// {
// 	while (i < 24)
// 	{
// 		mlx_put_pixel(all->game->image, all->game->px * BLOCK + i - 12,
			//all->game->py * BLOCK + j - 12, 0xFF0000FF);
// 		i++;
// 	}
// 	i = 0;
// 	j++;
// }
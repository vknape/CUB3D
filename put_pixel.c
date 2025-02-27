/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vknape <vknape@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 13:24:06 by snijhuis          #+#    #+#             */
/*   Updated: 2025/02/27 15:03:58 by vknape           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	print_mini_map(t_all *all, int i, int j, int offset_i, int offset_j)
{
	int			x;
	int			y;
	uint32_t	color;

	x = ((i + offset_i) / MINI_BLOCK);
	y = ((j + offset_j) / MINI_BLOCK);
	color = color_mini(all, x, y, 0, 0);
	mlx_put_pixel(all->game->image, i, j, color);
	

}

uint32_t	color_mini(t_all *all, int i, int j, int offset_i, int offset_j)
{
	uint32_t	color;

	color = 0;
	// i = 0;
	// j = 0;
	// if (floor(all->game->px) > MINI_LIMITS)
	// 	i = floor(all->game->px) - MINI_LIMITS;
	// if (floor(all->game->py) > MINI_LIMITS)
	// 	j = floor(all->game->py) - MINI_LIMITS;
	// if (i > all->parse->map_width)
	// 	i = all->parse->map_width -1;
	// if (j > all->parse->map_height)
	// 	j = all->parse->map_height - 1;
	// printf("%d\n", i);
	// printf("%d\n\n", j);
	if (i  >= all->parse->map_width|| i < 0 || j >= all->parse->map_height || j < 0)
		color = 0xAAAAAAFF;
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

void print_player(t_all *all, int limit_x, int limit_y)
{
	int i;
	int j;
	
	i = 0;
	j = 0;
	while (j < 16)
	{
		while (i < 16)
		{
			mlx_put_pixel(all->game->image, MINI_LIMITS * MINI_BLOCK + i - 8,
				MINI_LIMITS * MINI_BLOCK + j - 8, 0xFF0000FF);
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
			color = all->parse->hex_ceiling;//0xFFFFFFFF;
		else
			color = all->parse->hex_floor;//0x000000FF;
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
	int		limit_x;
	int		limit_y;
	uint32_t	color;

	color = color_mini(all, i, j, 0, 0);


	all = param;
	print_background(all);
	ft_raydir(all);
	i = 0;
	j = 0;
	limit_x = (all->game->px - MINI_LIMITS) * MINI_BLOCK;
	limit_y = (all->game->py - MINI_LIMITS) * MINI_BLOCK;
	// i = limit_x;
	// j = limit_y;
	while (j < MINI_LIMITS * MINI_BLOCK * 2)
	{
		while (i < MINI_LIMITS * MINI_BLOCK * 2)
		{
			print_mini_map(all, i, j, limit_x, limit_y);
			i++;
		}
		i = 0;
		j++;
	}
	print_player(all, 0, 0);
}

// void	ft_print(void *param)
// {
// 	t_all	*all;
// 	int		i;
// 	int		j;
// 	int		offset_i;
// 	int		offset_j;
// 	int		limit_x;
// 	int		limit_y;

// 	all = param;
// 	print_background(all);
// 	ft_raydir(all);
// 	i = 0;
// 	j = 0;
// 	offset_i = 0;
// 	offset_j = 0;
// 	limit_x = 2 * MINI_LIMITS;
// 	limit_y = 2 * MINI_LIMITS;
// 	if (floor(all->game->px) >= MINI_LIMITS)
// 		offset_i = floor(all->game->px) - MINI_LIMITS;
// 	if (offset_i + 2 * MINI_LIMITS >= all->parse->map_width)
// 		offset_i = all->parse->map_width - 1 - 2 * MINI_LIMITS;
// 	if (floor(all->game->py) >= MINI_LIMITS)
// 		offset_j = floor(all->game->py) - MINI_LIMITS;
// 	if (offset_j + 2 * MINI_LIMITS >= all->parse->map_height)
// 		offset_j = all->parse->map_height - 1 - 2 * MINI_LIMITS;
// 	if (all->parse->map_width < 2 * MINI_LIMITS)
// 	{
// 		offset_i = 0;
// 		limit_x = all->parse->map_width - 1;
// 	}
// 	if (all->parse->map_height < 2 * MINI_LIMITS)
// 	{
// 		offset_j = 0;
// 		limit_y = all->parse->map_height - 1;
// 	}
// 	while (j < limit_y)
// 	{
// 		while (i < limit_x)
// 		{
// 			print_mini_map(all, i, j, offset_i, offset_j);
// 			i++;
// 		}
// 		i = 0;
// 		j++;
// 	}
// 	print_player(all, limit_x, limit_y);
// }

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
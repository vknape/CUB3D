/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   put_pixel.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: snijhuis <snijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/21 13:24:06 by snijhuis      #+#    #+#                 */
/*   Updated: 2025/01/23 11:52:39 by snijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	print_pixel(t_all *all, int i, int j)
{
	int	x;
	int	y;
	uint32_t color;

	if (all->parse->map[j][i] == space)
		color = 0x00000000;
	else if (all->parse->map[j][i] == ground)
		color = 0xFFFFFFFF;
	else if (all->parse->map[j][i] == wall)
		color = 0x000000FF;
	else
		color = 0xFF0000FF;
	x = 0;
	y = 0;
	while (y < BLOCK)
	{
		while (x < BLOCK)
		{
			mlx_put_pixel(all->game->image, i * BLOCK + x, j * BLOCK + y, color);
			x++;
		}
		x = 0;
		y++;
	}
}

void	ft_hook(void *param)
{
	t_all	*all;
	int	i;
	int	j;

	all = param;
	i = 0;
	j = 0;
	while (all->parse->map[j])
	{
		while (all->parse->map[j][i])
		{
			print_pixel(all, i, j);
			i++;
		}
		i = 0;
		j++;
	}
	i = 0;
	j = 0;
	while (j < 24)
	{
		while (i < 24)
		{
			mlx_put_pixel(all->game->image, all->game->px * BLOCK + i - 12, all->game->py * BLOCK + j - 12, 0xFF0000FF);
			i++;
		}
		i = 0;
		j++;
	}
	// printf("%f\n", all->game->window->delta_time);
}
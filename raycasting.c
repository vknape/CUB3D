/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycasting.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: snijhuis <snijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/21 13:19:14 by snijhuis      #+#    #+#                 */
/*   Updated: 2025/01/21 15:05:43 by snijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"


void	ft_raydir(void *param)
{
	t_all	*all;
	double	dir;
	int		i;
	
	all = param;
	dir = all->game->p_or - fov / 2;
	i = 0;
	while (i < 360)
	{
		dir += fov / 360;
		all->game->dirx = cos(dir);
		all->game->diry = -sin(dir);
		draw_ray(all);
		i++;
	}
	
}

void	draw_ray(t_all *all)
{
		int	i;
	double	x;
	double	y;

	// printf("%f\n", all->game->dirx);
	// printf("%f\n", all->game->diry);
	i = 0;
	while (i < 200)
	{
		// printf("%f\n", all->game->p_or);
		x = all->game->px * BLOCK + (all->game->dirx * i) + 12;
		y = all->game->py * BLOCK + (all->game->diry * i);
		// printf("%f\n", all->game->px);
		// printf("%f\n", all->game->py);
		// printf("%f\n", x);
		// printf("%f\n\n", y);
		// if (!(x < 0 || x > all->game->img_width || y < 0 || y > all->game->img_height))
		if (x < 0)
			x = 0;
		if (y < 0)
			y = 0;
		if (x > all->game->img_width)
			x = all->game->img_width;
		if (y > all->game->img_height)
			y = all->game->img_height;
		mlx_put_pixel(all->game->image, x, y, 0xFF0000FF);
		// mlx_put_pixel(all->game->image, x + 1, y, 0xFF0000FF);
		// mlx_put_pixel(all->game->image, x + 2, y, 0xFF0000FF);
		i++;
	}
	// while (1)
	// ;
}
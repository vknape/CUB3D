/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycasting.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: snijhuis <snijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/21 13:19:14 by snijhuis      #+#    #+#                 */
/*   Updated: 2025/01/23 15:40:29 by snijhuis      ########   odam.nl         */
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
	ray_end(all);
	while (i < 200)
	{
		// printf("%f\n", all->game->p_or);
		x = all->game->px * BLOCK + (all->game->dirx * i);
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

void ray_end(t_all *all)
{
	double x;
	double y;
	double slope;
	double step_size;

	step_size = 1.0 / all->game->dirx;
	x = all->game->px;
	y = all->game->py;
	slope = all->game->dirx / all->game->diry;
	while(1)
	{
		
		x = floor(all->game->px);
		y = floor(all->game->py);
		if (all->parse->map[(int)y][(int)x] == wall)
			break;	
	}
}

// void wall_collision(t_all *all)
// {
// 	double x;
// 	double y;
// 	double xnew;
// 	double ynew;
// 	// int		index;

// 	all->game->dirx = cos(all->game->p_or);
// 	all->game->diry = -sin(all->game->p_or);

// 	x = all->game->px * BLOCK;
// 	y = all->game->py * BLOCK;
// 	xnew = x + (all->game->dirx * STEP * BLOCK);
// 	ynew = y + (all->game->diry * STEP * BLOCK);
// 	printf("xnew: %f\n", xnew);
// 	printf("ynew: %f\n", ynew);

// 	x = floor(xnew / BLOCK);
// 	y = floor(ynew / BLOCK);
// 	if (all->parse->map[(int)y][(int)x] != wall)
// 	{
// 		all->game->px = xnew / BLOCK;
// 		all->game->py = ynew / BLOCK;
// 	}
// }
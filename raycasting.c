/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycasting.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: vknape <vknape@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/21 13:19:14 by snijhuis      #+#    #+#                 */
/*   Updated: 2025/02/06 15:32:06 by snijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"


void	ft_raydir(void *param)
{
	t_all	*all;
	double	dir;
	double 	or;
	int		i;
	
	all = param;
	dir = all->game->p_or - fov / 2;
	or = all->game->p_or;
	i = 0;
	while (i < 90)
	{
		dir += fov / 90;
		if (dir < 0)
			dir += 2 * pi;
		if (dir > 2 * pi)
			dir -= 2 * pi;
		all->game->p_or = dir;
		all->game->dirx = cos(dir);
		all->game->diry = -sin(dir);
		// draw_ray(all);
		draw_ray3d(all, i);
		i++;
	}
	all->game->p_or = or;
	
}

void	draw_ray3d(t_all *all, int z)
{
	int	i;
	int	j;
	double height;
	// double	x;
	// double	y;

	i = 0;
	j = 0;
	calculate_ray(all);
	height = WINDOW_Y / (all->ray->ray_length * BLOCK);

	while (i < (WINDOW_X / 90))
	{
		while (j < height)
		{
			mlx_put_pixel(all->game->image, ((WINDOW_X / 90 * z) + i), (WINDOW_Y / 2) - (height / 2) + j, 0xF0F0F0FF); //(WINDOW_Y / 2) - (height / 2) + j
			j++;
		}
		j = 0;
		i++;
	}

}

void	draw_ray(t_all *all)
{
	int	i;
	double	x;
	double	y;

	i = 0;
	calculate_ray(all);
	while (i < all->ray->ray_length * BLOCK)
	{
		x = all->game->px * BLOCK + (all->game->dirx * i);
		y = all->game->py * BLOCK + (all->game->diry * i); 
		mlx_put_pixel(all->game->image, x, y, 0xFF0000FF);
		i++;
	}
}


void	calculate_ray(t_all *all)
{
	if (all->game->p_or > 0.5 * pi && all->game->p_or < 1.5 * pi)
		all->ray->xneg = true;
	else
		all->ray->xneg = false;
	if (all->game->p_or > 0 && all->game->p_or < pi)
		all->ray->yneg = true;
	else
		all->ray->yneg = false;
	ray_end_xpos(all);
	ray_end_ypos(all);
}

void assign_ray(t_all *all, int id)
{
	if (id == 1)
	{
		all->ray->ray_x = all->ray->calc_x;
		all->ray->ray_y = all->ray->calc_y;
		all->ray->ray_length = all->ray->calc_ray;
		all->ray->valid_ray = true;
	}
	if (id == 2)
		all->ray->valid_ray = false;

}

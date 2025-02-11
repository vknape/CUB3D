/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycasting.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: vknape <vknape@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/21 13:19:14 by snijhuis      #+#    #+#                 */
/*   Updated: 2025/02/11 15:57:15 by snijhuis      ########   odam.nl         */
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
	while (i < WINDOW_X)
	{
		dir += fov / WINDOW_X;
		if (dir < 0)
			dir += 2 * pi;
		if (dir > 2 * pi)
			dir -= 2 * pi;
		all->game->p_or = dir;
		all->game->dirx = cos(dir);
		all->game->diry = -sin(dir);
		render_line(all, i, dir);
		// draw_ray(all);
		// draw_ray3d(all, i);
		i++;
	}
	all->game->p_or = or;
	
}

void	render_line(t_all *all, int i, double dir)
{
	double	y;
	double 	ray_diff;
	double 	dist;
	// double	tex_y;
	// double	tex_x;
	uint32_t color;

	calculate_ray(all);
	ray_diff = dir - all->game->p_or;
	dist = all->ray->ray_length * cos(ray_diff);
	all->ray->wall_height = WINDOW_Y / dist;
	all->ray->wall_top = WINDOW_Y / 2 - all->ray->wall_height / 2;
	all->ray->wall_bottom = WINDOW_Y / 2 + all->ray->wall_height / 2;
	if (all->ray->wall_top < 0)
		all->ray->wall_top = 0;
	if (all->ray->wall_bottom >= WINDOW_Y)
		all->ray->wall_bottom = 0;
	// x = fmod
	y = 0;
	while (y < all->ray->wall_height)
	{
		color = texture_color(all, y);
		// printf("x = %d\n", WINDOW_X - i);
		// printf("y = %lf\n\n", all->ray->wall_bottom - y);
		if (all->ray->wall_top + y > WINDOW_Y - 1)
		{
			printf("went out of bounce with y\n");
			return ;
		}
		mlx_put_pixel(all->game->image, WINDOW_X - i, all->ray->wall_top + y , color);
		y++;
	}



	
}

uint32_t	texture_color(t_all *all, double tex_y)
{
	uint32_t	color;
	int			index;
	int			tex_x;

	tex_x = fmod(all->ray->ray_x, 1.0) * all->ray->texture->width;
	index = (all->ray->texture->width * tex_y + tex_x) * 4;
	color = 0;
	color += all->ray->texture->pixels[index] << 24;
	color += all->ray->texture->pixels[index + 1] << 16;
	color += all->ray->texture->pixels[index + 2] << 8;
	color += 255;
	return (color);
	
	
	
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

void assign_ray(t_all *all, int id, char axis)
{
	if (id == 1)
	{
		all->ray->ray_x = all->ray->calc_x;
		all->ray->ray_y = all->ray->calc_y;
		all->ray->ray_length = all->ray->calc_ray;
		all->ray->valid_ray = true;
		if (axis == 'x')
		{
			if (all->game->p_or > 0.5 * pi && all->game->p_or < 1.5 * pi)
				all->ray->texture = all->texture->east;
			else
				all->ray->texture = all->texture->west;
		}
		if (axis == 'y')
		{
			if (all->game->p_or > 0 && all->game->p_or < pi)
				all->ray->texture = all->texture->south;
			else
				all->ray->texture = all->texture->north;
		}
	}
	if (id == 2)
		all->ray->valid_ray = false;
}

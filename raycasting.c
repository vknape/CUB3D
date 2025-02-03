/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycasting.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: vknape <vknape@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/21 13:19:14 by snijhuis      #+#    #+#                 */
/*   Updated: 2025/02/03 15:13:18 by snijhuis      ########   odam.nl         */
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
		draw_ray(all);
		i++;
	}
	all->game->p_or = or;
	
}

void	draw_ray(t_all *all)
{
	int	i;
	double	x;
	double	y;

	i = 0;
	posy_posx(all);
	while (i < all->ray->ray_length * BLOCK)
	{
		x = all->game->px * BLOCK + (all->game->dirx * i);
		y = all->game->py * BLOCK + (all->game->diry * i); 
		mlx_put_pixel(all->game->image, x, y, 0xFF0000FF);
		i++;
	}
}

void	posy_posx(t_all *all)
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

void ray_end_xpos(t_all *all)
{
	all->ray->calc_x = fmod(all->game->px, 1.0);
	all->ray->calc_y = all->game->py;
	if (!all->ray->xneg)
		all->ray->calc_x = 1 - all->ray->calc_x;
	all->ray->calc_or = all->game->p_or;
	if (all->ray->calc_or > pi)
		all->ray->calc_or = (2 * pi) - all->ray->calc_or;
	if (all->ray->xneg)
		all->ray->calc_or = pi - all->ray->calc_or;
	all->ray->calc_ray = all->ray->calc_x / cos(all->ray->calc_or);
	if (all->ray->yneg)
		all->ray->calc_y -= tan(all->ray->calc_or) * all->ray->calc_x;
	else
		all->ray->calc_y += tan(all->ray->calc_or) * all->ray->calc_x;
	if (all->ray->xneg)
		all->ray->calc_x = floor(all->game->px) - 1;
	else
		all->ray->calc_x = floor(all->game->px) + 1;
	if (all->ray->calc_x > all->parse->map_width || all->ray->calc_y > all->parse->map_height || all->ray->calc_x < 0 || all->ray->calc_y < 0)
		return(assign_ray(all, 2));
	if (all->parse->map[(int)floor(all->ray->calc_y)][(int)floor(all->ray->calc_x)] == wall)
		return(assign_ray(all, 1));
		
	while (1)
	{
		if (all->ray->xneg)
			all->ray->calc_x--;
		else
			all->ray->calc_x++;
		all->ray->calc_ray += (1 / cos(all->ray->calc_or));
		if (all->ray->yneg)
			all->ray->calc_y -= tan(all->ray->calc_or) * 1;
		else
			all->ray->calc_y += tan(all->ray->calc_or) * 1;
		if (all->ray->calc_x >= all->parse->map_width || all->ray->calc_y >= all->parse->map_height || all->ray->calc_x < 0 || all->ray->calc_y < 0)
			return(assign_ray(all, 2));
		if (all->parse->map[(int)floor(all->ray->calc_y)][(int)floor(all->ray->calc_x)] == wall)
			return(assign_ray(all, 1));
	}
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

void ray_end_ypos(t_all *all)
{
	double	x;
	double	y;
	double	ray;
	double	or;

	if (all->ray->yneg)
	{
		y = fmod(all->game->py, 1.0);
		x = all->game->px;
		or = all->game->p_or;
		if (or > pi)
			or = (2 * pi) - or;
		if (or == 0 || or == pi)
			return ;
		if (or > 0.5 * pi)
			or = pi - or;
		ray = y / sin(or);
		if (all->ray->xneg)
			x -= y / tan(or);
		else
			x += y / tan(or);
		y = floor(all->game->py);
		y -= 1;
		if (x >= all->parse->map_width || y >= all->parse->map_height || x < 0 || y < 0)
		{
			all->ray->valid_ray = false;
			return ;
		}
		if (all->parse->map[(int)floor(y)][(int)floor(x)] == wall)
		{
			if (all->ray->valid_ray == false || ray < all->ray->ray_length)
			{
				all->ray->ray_x = x;
				all->ray->ray_y = y;
				all->ray->ray_length = ray;
				all->ray->valid_ray = true;
			}
			return ;
		}
		while (1)
		{
			y--;
			ray += (1 / sin(or));
			if (all->ray->xneg)
				x -= 1 / tan(or);
			else
				x += 1 / tan(or);
			if (x >= all->parse->map_width || y >= all->parse->map_height || x < 0 || y < 0)
			{
				all->ray->valid_ray = false;
				break ;
			}
			if (all->parse->map[(int)floor(y)][(int)floor(x)] == wall)
			{
				if (all->ray->valid_ray == false || ray < all->ray->ray_length)
				{
					all->ray->ray_x = x;
					all->ray->ray_y = y;
					all->ray->ray_length = ray;
					all->ray->valid_ray = true;
				}
				break ;
			}
		}
	}
	else
	{
		y = fmod(all->game->py, 1.0);
		x = all->game->px;
		y = 1 - y;
		or = all->game->p_or;
		if (or > pi)
			or = (2 * pi) - or;
		if (or == 0 || or == pi)
			return ;
		if (or > 0.5 * pi)
			or = pi - or;
		ray = y / sin(or);
		if (all->ray->xneg)
			x -= y / tan(or);
		else
			x += y / tan(or);
		y = ceil(y) + floor(all->game->py);
		if (x >= all->parse->map_width || y >= all->parse->map_height || x < 0 || y < 0)
		{
			all->ray->valid_ray = false;
			return ;
		}
		if (all->parse->map[(int)floor(y)][(int)floor(x)] == wall)
		{
			if (all->ray->valid_ray == false || ray < all->ray->ray_length)
			{
				all->ray->ray_x = x;
				all->ray->ray_y = y;
				all->ray->ray_length = ray;
				all->ray->valid_ray = true;
			}
			return ;
		}
		while (1)
		{
			y++;
			ray += (1 / sin(or));
			if (all->ray->xneg)
				x -= 1 / tan(or);
			else
				x += 1 / tan(or);
			if (x >= all->parse->map_width || y >= all->parse->map_height || x < 0 || y < 0)
			{
				all->ray->valid_ray = false;
				break ;
			}
			if (all->parse->map[(int)floor(y)][(int)floor(x)] == wall)
			{
				if (all->ray->valid_ray == false || ray < all->ray->ray_length)
				{
					all->ray->ray_x = x;
					all->ray->ray_y = y;
					all->ray->ray_length = ray;
					all->ray->valid_ray = true;
				}
				break ;
			}
		}
	}
}

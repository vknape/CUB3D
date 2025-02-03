/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycasting.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: vknape <vknape@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/21 13:19:14 by snijhuis      #+#    #+#                 */
/*   Updated: 2025/02/03 14:37:17 by snijhuis      ########   odam.nl         */
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
	double	x;
	double	y;
	double	ray;
	double	or;

	if (all->ray->xneg)
	{
		x = fmod(all->game->px, 1.0);
		y = all->game->py;
		or = all->game->p_or;
		if (or > pi)
			or = (2 * pi) - or;
		or = pi - or;
		ray = x / cos(or);
		if (all->ray->yneg)
			y -= tan(or) * x;
		else
			y += tan(or) * x;
		x = floor(all->game->px);
		x -= 1;
		if (x > all->parse->map_width || y > all->parse->map_height  || x < 0 || y < 0)
		{
			all->ray->valid_ray = false;
			return ;
		}
		if (all->parse->map[(int)floor(y)][(int)floor(x)] == wall)
		{
			all->ray->ray_x = x;
			all->ray->ray_y = y;
			all->ray->ray_length = ray;
			all->ray->valid_ray = true;
			return ;
		}
		while (1)
		{
			x--;
			ray += (1 / cos(or));
			if (all->ray->yneg)
				y -= tan(or) * 1;
			else
				y += tan(or) * 1;
			if (x >= all->parse->map_width || y >= all->parse->map_height || x < 0 || y < 0)
			{
				all->ray->valid_ray = false;
				break ;
			}
			if (all->parse->map[(int)floor(y)][(int)floor(x)] == wall)
			{
				all->ray->ray_x = x;
				all->ray->ray_y = y;
				all->ray->ray_length = ray;
				all->ray->valid_ray = true;
				break ;
			}
		}
	}
	else
	{
		x = fmod(all->game->px, 1.0);
		y = all->game->py;
		x = 1 - x;
		or = all->game->p_or;
		if (or > pi)
			or = (2 * pi) - or;
		if (or == 0.5 * pi)
			return ;
		ray = x / cos(or);
		if (all->ray->yneg)
			y -= tan(or) * x;
		else
			y += tan(or) * x;
		x = ceil(x) + floor(all->game->px);
		if (x > all->parse->map_width || y > all->parse->map_height || x < 0 || y < 0)
		{
			all->ray->valid_ray = false;
			return ;
		}
		if (all->parse->map[(int)floor(y)][(int)floor(x)] == wall)
		{
			all->ray->ray_x = x;
			all->ray->ray_y = y;
			all->ray->ray_length = ray;
			all->ray->valid_ray = true;
			return ;
		}
		while (1)
		{
			x++;
			ray += (1 / cos(or));
			if (all->ray->yneg)
				y -= tan(or) * 1;
			else
				y += tan(or) * 1;
			if (x >= all->parse->map_width || y >= all->parse->map_height || x < 0 || y < 0)
			{
				all->ray->valid_ray = false;
				break ;
			}
			if (all->parse->map[(int)floor(y)][(int)floor(x)] == wall)
			{
				all->ray->ray_x = x;
				all->ray->ray_y = y;
				all->ray->ray_length = ray;
				all->ray->valid_ray = true;
				break ;
			}
		}
	}
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

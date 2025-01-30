/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vknape <vknape@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 13:19:14 by snijhuis          #+#    #+#             */
/*   Updated: 2025/01/30 15:34:34 by vknape           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"


void	ft_raydir(void *param)
{
	t_all	*all;
	double	dir;
	int		i;
	
	all = param;
	// dir = all->game->p_or - fov / 2;
	dir = all->game->p_or;
	i = 0;
	while (i < 1)
	{
		// dir += fov / 90;
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
	// ray_end_y(all);
	posy_posx(all);
	while (i < all->ray->ray_length * BLOCK)
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

void ray_end_x(t_all *all)
{
	double	x;
	double	y;
	double	ray;
	double	or;

	x = fmod(all->game->px, 1.0);
	y = all->game->py;
	x = 1 - x;
	or = all->game->p_or;
	if (or > pi)
		or = (2 * pi) - or;
	// y = 1 - y;
	ray = x / cos(or);
	y += tan(or) * x;
	x = ceil(x) + floor(all->game->px);
	if (all->parse->map[(int)floor(y)][(int)floor(x)] == wall)
	{
		// printf("x = %f\n", floor(x));
		// printf("y = %f\n", floor(y));
		// printf("ray = %f\n\n", ray);
		return ;
	}
	while (1)
	{
		x++;
		ray += (1 / cos(or));
		y += tan(or);
		if (x > all->parse->map_width || y > all->parse->map_height)
		{
			printf("Out of bounds\n");
			break ;
		}
		if (all->parse->map[(int)floor(y)][(int)floor(x)] == wall)
		{
			// printf("x = %f\n", floor(x));
			// printf("y = %f\n", floor(y));
			// printf("ray = %f\n\n", ray);
			break ;
		}
	}
	
}

void ray_end_y(t_all *all)
{
	double	x;
	double	y;
	double	ray;
	double	or;

	y = fmod(all->game->py, 1.0);
	x = all->game->px;
	y = 1 - y;
	or = all->game->p_or;
	if (or > pi)
		or = (2 * pi) - or;
	// y = 1 - y;
	if (or == 0)
		return ;
	ray = y / sin(or);
	x += y / tan(or);
	y = ceil(y) + floor(all->game->py);
	// printf("x = %f\n", floor(x));
	// printf("y = %f\n", floor(y));
	// printf("ray = %f\n\n", ray);
	if (all->parse->map[(int)floor(y)][(int)floor(x)] == wall)
	{
		// printf("x = %f\n", floor(x));
		// printf("y = %f\n", floor(y));
		// printf("ray = %f\n\n", ray);
		return ;
	}
	while (1)
	{
		y++;
		ray += (1 / sin(or));
		x += y / tan(or);
		// printf("x = %f\n", floor(x));
		// printf("y = %f\n", floor(y));
		// printf("ray = %f\n\n", ray);
		if (x > all->parse->map_width || y > all->parse->map_height)
		{
			printf("Out of bounds\n");
			break ;
		}
		if (all->parse->map[(int)floor(y)][(int)floor(x)] == wall)
		{
			printf("%c\n", all->parse->map[(int)floor(y)][(int)floor(x)]);
			printf("x = %f\n", floor(x));
			printf("y = %f\n", floor(y));
			printf("ray = %f\n\n", ray);
			break ;
		}
	}
}

// void	ray_calculations(t_all *all)
// {
// 	if (all->game->p_or <= 0.5 * pi)
// 		negy_posx(all);
// 	else if (all->game->p_or <= pi)
// 		negy_negx(all);
// 	else if (all->game->p_or <= 1.5 * pi)
// 		posy_negx(all);
// 	else if (all->game->p_or <= 2 * pi)
// 		posy_posx(all);
	
// }

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
	printf("x = %f\n", all->ray->ray_x);
	printf("y = %f\n", all->ray->ray_y);
	printf("ray = %f\n\n", all->ray->ray_length);
}

void ray_end_xpos(t_all *all)
{
	double	x;
	double	y;
	double	ray;
	double	or;

	if (all->ray->xneg)
	{
		printf("neg\n");
		x = fmod(all->game->px, 1.0);
		y = all->game->py;
		or = all->game->p_or;
		if (or > pi)
			or = (2 * pi) - or;
		or = pi - or;
		ray = x / cos(or);
		y += tan(or) * x;
		x = floor(all->game->px);
		// printf("seg px = %f\n", all->game->px);
		// printf("seg py = %f\n", all->game->py);
		// printf("seg x = %f\n", floor(x));
		// printf("seg y = %f\n", floor(y));
		// printf("seg ray = %f\n\n", ray);
		x -= 1;
		if (x > all->parse->map_width || y > all->parse->map_height)
		{
			all->ray->valid_ray = false;
			printf("x 1\n");
			return ;
		}
		if (all->parse->map[(int)floor(y)][(int)floor(x)] == wall)
		{
			all->ray->ray_x = x;
			all->ray->ray_y = y;
			all->ray->ray_length = ray;
			all->ray->valid_ray = true;
			printf("x 2\n");
			return ;
		}
		printf("seg px = %f\n", all->game->px);
		printf("seg py = %f\n", all->game->py);
		printf("seg x = %f\n", floor(x));
		printf("seg y = %f\n", floor(y));
		printf("seg ray = %f\n\n", ray);
		while (1)
		{
			x--;
			ray += (1 / cos(or));
			y += tan(or) * 1;
			printf("seg px = %f\n", all->game->px);
			printf("seg py = %f\n", all->game->py);
			printf("seg x = %f\n", floor(x));
			printf("seg y = %f\n", floor(y));
			printf("seg ray = %f\n\n", ray);
			if (x > all->parse->map_width || y > all->parse->map_height)
			{
				all->ray->valid_ray = false;
				printf("x 3\n");
				break ;
			}
			if (all->parse->map[(int)floor(y)][(int)floor(x)] == wall)
			{
				all->ray->ray_x = x;
				all->ray->ray_y = y;
				all->ray->ray_length = ray;
				all->ray->valid_ray = true;
				printf("x 4\n");
				break ;
			}
		}
	}
	else
	{
		printf("pos\n");
		x = fmod(all->game->px, 1.0);
		y = all->game->py;
		x = 1 - x;
		or = all->game->p_or;
		if (or > pi)
			or = (2 * pi) - or;
		if (or == 0.5 * pi)
			return ;
		ray = x / cos(or);
		y += tan(or) * x;
		x = ceil(x) + floor(all->game->px);
		printf("seg px = %f\n", all->game->px);
		printf("seg py = %f\n", all->game->py);
		printf("seg x = %f\n", floor(x));
		printf("seg y = %f\n", floor(y));
		printf("seg ray = %f\n\n", ray);
		if (x > all->parse->map_width || y > all->parse->map_height)
		{
			all->ray->valid_ray = false;
			printf("x 1\n");
			return ;
		}
		if (all->parse->map[(int)floor(y)][(int)floor(x)] == wall)
		{
			all->ray->ray_x = x;
			all->ray->ray_y = y;
			all->ray->ray_length = ray;
			all->ray->valid_ray = true;
			printf("x 2\n");
			return ;
		}
		while (1)
		{
			x++;
			ray += (1 / cos(or));
			y += tan(or) * 1;
			if (x > all->parse->map_width || y > all->parse->map_height)
			{
				all->ray->valid_ray = false;
				printf("x 3\n");
				break ;
			}
			if (all->parse->map[(int)floor(y)][(int)floor(x)] == wall)
			{
				all->ray->ray_x = x;
				all->ray->ray_y = y;
				all->ray->ray_length = ray;
				all->ray->valid_ray = true;
				printf("x 4\n");
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
		or = pi - or;
		ray = y / sin(or);
		x += y / tan(or);
		y = floor(all->game->py);
		// printf("seg px = %f\n", all->game->px);
		// printf("seg py = %f\n", all->game->py);
		// printf("seg x = %f\n", floor(x));
		// printf("seg y = %f\n", floor(y));
		// printf("seg ray = %f\n\n", ray);
		y -= 1;
		if (x > all->parse->map_width || y > all->parse->map_height)
		{
			all->ray->valid_ray = false;
			printf("y 1\n");
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
				printf("y 2\n");
			}
			return ;
		}
		while (1)
		{
			y--;
			ray += (1 / sin(or));
			x += 1 / tan(or);
			if (x > all->parse->map_width || y > all->parse->map_height)
			{
				all->ray->valid_ray = false;
				printf("y 3\n");
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
					printf("y 4\n");
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
		ray = y / sin(or);
		x += y / tan(or);
		y = ceil(y) + floor(all->game->py);
		// printf("seg px = %f\n", all->game->px);
		// printf("seg py = %f\n", all->game->py);
		// printf("seg x = %f\n", floor(x));
		// printf("seg y = %f\n", floor(y));
		// printf("seg ray = %f\n\n", ray);
		if (x > all->parse->map_width || y > all->parse->map_height)
		{
			all->ray->valid_ray = false;
			printf("y 1\n");
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
				printf("y 2\n");
			}
			return ;
		}
		while (1)
		{
			y++;
			ray += (1 / sin(or));
			x += 1 / tan(or);
			if (x > all->parse->map_width || y > all->parse->map_height)
			{
				all->ray->valid_ray = false;
				printf("y 3\n");
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
					printf("y 4\n");
				}
				break ;
			}
		}
	}
}

void ray_end_xneg(t_all *all)
{
	double	x;
	double	y;
	double	ray;
	double	or;

	x = fmod(all->game->px, 1.0);
	y = all->game->py;
	x = 1 - x;
	or = all->game->p_or;
	if (or > pi)
		or = (2 * pi) - or;
	ray = x / cos(or);
	y += tan(or) * x;
	x = ceil(x) + floor(all->game->px);
	if (all->parse->map[(int)floor(y)][(int)floor(x)] == wall)
		return ;
	while (1)
	{
		x++;
		ray += (1 / cos(or));
		y += tan(or);
		if (x > all->parse->map_width || y > all->parse->map_height)
			break ;
		if (all->parse->map[(int)floor(y)][(int)floor(x)] == wall)
			break ;
	}
}

void ray_end_yneg(t_all *all)
{
	double	x;
	double	y;
	double	ray;
	double	or;

	y = fmod(all->game->py, 1.0);
	x = all->game->px;
	y = 1 - y;
	or = all->game->p_or;
	if (or > pi)
		or = (2 * pi) - or;
	if (or == 0)
		return ;
	ray = y / sin(or);
	x += y / tan(or);
	y = ceil(y) + floor(all->game->py);
	if (all->parse->map[(int)floor(y)][(int)floor(x)] == wall)
		return ;
	while (1)
	{
		y++;
		ray += (1 / sin(or));
		x += y / tan(or);
		if (x > all->parse->map_width || y > all->parse->map_height)
			break ;
		if (all->parse->map[(int)floor(y)][(int)floor(x)] == wall)
			break ;
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
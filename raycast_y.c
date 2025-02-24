/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycast_y.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: snijhuis <snijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/06 12:02:59 by snijhuis      #+#    #+#                 */
/*   Updated: 2025/02/24 11:54:31 by snijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ray_end_ypos(t_all *all)
{
	all->ray->calc_y = fmod(all->game->py, 1.0);
	all->ray->calc_x = all->game->px;
	if (!all->ray->yneg)
		all->ray->calc_y = 1 - all->ray->calc_y;
	all->ray->calc_or = all->game->p_or;
	if (all->ray->calc_or > pi)
		all->ray->calc_or = (2 * pi) - all->ray->calc_or;
	if (all->ray->calc_or == 0 || all->ray->calc_or == pi)
		return ;
	if (all->ray->calc_or > 0.5 * pi)
		all->ray->calc_or = pi - all->ray->calc_or;
	all->ray->calc_ray = all->ray->calc_y / sin(all->ray->calc_or);
	if (all->ray->xneg)
		all->ray->calc_x -= all->ray->calc_y / tan(all->ray->calc_or);
	else
		all->ray->calc_x += all->ray->calc_y / tan(all->ray->calc_or);
	if (all->ray->yneg)
		all->ray->calc_y = floor(all->game->py) - 1;
	else
		all->ray->calc_y = floor(all->game->py) + 1;
	if (all->ray->calc_x >= all->parse->map_width
		|| all->ray->calc_y >= all->parse->map_height || all->ray->calc_x < 0
		|| all->ray->calc_y < 0)
		return (assign_ray(all, 2, '0'));
	if (all->parse->map[(int)floor(all->ray->calc_y)][(int)floor(all->ray->calc_x)] == wall)
		if (all->ray->valid_ray == false
			|| all->ray->calc_ray < all->ray->ray_length)
			return (assign_ray(all, 1, 'y'));
	ray_ypos_loop(all);
}

void	ray_ypos_loop(t_all *all)
{
	while (1)
	{
		if (all->ray->yneg)
			all->ray->calc_y--;
		else
			all->ray->calc_y++;
		all->ray->calc_ray += (1 / sin(all->ray->calc_or));
		if (all->ray->xneg)
			all->ray->calc_x -= 1 / tan(all->ray->calc_or);
		else
			all->ray->calc_x += 1 / tan(all->ray->calc_or);
		if (all->ray->calc_x >= all->parse->map_width
			|| all->ray->calc_y >= all->parse->map_height
			|| all->ray->calc_x < 0 || all->ray->calc_y < 0)
			return (assign_ray(all, 2, '0'));
		if (all->parse->map[(int)floor(all->ray->calc_y)][(int)floor(all->ray->calc_x)] == wall)
			if (all->ray->valid_ray == false
				|| all->ray->calc_ray < all->ray->ray_length)
				return (assign_ray(all, 1, 'y'));
	}
}

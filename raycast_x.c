/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycast_x.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: snijhuis <snijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/06 11:36:25 by snijhuis      #+#    #+#                 */
/*   Updated: 2025/02/11 14:13:07 by snijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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
		return(assign_ray(all, 2, '0'));
	if (all->parse->map[(int)floor(all->ray->calc_y)][(int)floor(all->ray->calc_x)] == wall)
		return(assign_ray(all, 1, 'x'));
	ray_xpos_loop(all);
}

void ray_xpos_loop (t_all *all)
{
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
			return(assign_ray(all, 2, '0'));
		if (all->parse->map[(int)floor(all->ray->calc_y)][(int)floor(all->ray->calc_x)] == wall)
			return(assign_ray(all, 1, 'x'));
	}
}

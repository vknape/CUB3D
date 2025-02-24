/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_boundaries.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: vknape <vknape@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/15 11:53:33 by vknape        #+#    #+#                 */
/*   Updated: 2025/02/24 11:36:33 by snijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// Checks if the wall surrounding the ground are always closed

void	check_map_boundaries(t_all *all)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (all->parse->map[j])
	{
		check_map_row(all, j);
		j++;
	}
	j = 0;
	while (all->parse->map[j][i])
	{
		check_map_column(all, i);
		i++;
	}
}

void	check_map_row(t_all *all, int j)
{
	int		i;
	bool	start_ground;

	i = 1;
	start_ground = false;
	if (all->parse->map[j][0] == ground)
		clean_all(all, 0);
	while (all->parse->map[j][i])
	{
		if (start_ground == false && all->parse->map[j][i] == ground)
		{
			if (all->parse->map[j][i - 1] == space)
				clean_all(all, 0);
			start_ground = true;
		}
		if (start_ground == true && all->parse->map[j][i] == space)
			clean_all(all, 0);
		if (start_ground == true && all->parse->map[j][i] == wall)
			start_ground = false;
		i++;
	}
	if (start_ground == true)
		clean_all(all, 0);
}

void	check_map_column(t_all *all, int i)
{
	int		j;
	bool	start_ground;

	j = 1;
	start_ground = false;
	if (all->parse->map[0][i] == ground)
		clean_all(all, 0);
	while (all->parse->map[j])
	{
		if (start_ground == false && all->parse->map[j][i] == ground)
		{
			if (all->parse->map[j - 1][i] == space)
				clean_all(all, 0);
			start_ground = true;
		}
		if (start_ground == true && all->parse->map[j][i] == space)
			clean_all(all, 0);
		if (start_ground == true && all->parse->map[j][i] == wall)
			start_ground = false;
		j++;
	}
	if (start_ground == true)
		clean_all(all, 0);
}

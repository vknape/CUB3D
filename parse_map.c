/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vknape <vknape@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:10:36 by snijhuis          #+#    #+#             */
/*   Updated: 2025/01/16 14:47:00 by vknape           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

//Allocates 2d array and stores each character from the map part of the
//file on an individual index

void	parse_map(t_all *all)
{
	int	i;

	all->parse->map = ft_calloc(all->parse->map_height + 1, sizeof(char *));
	if (!all->parse->map)
		clean_all(all, 1);
	i = 0;
	while (i < all->parse->map_height)
	{
		all->parse->map[i] = ft_calloc(all->parse->map_width + 1, sizeof(char));
		if (!all->parse->map[i])
			clean_all(all, 1);
		i++;
	}
	read_map(all);
	return ;
}

//Print for testing
void	print_map(t_all *all)
{
	int	i;
	int	j;

	i = 0;
	j = 0;

	while (all->parse->map[j])
	{
		while (all->parse->map[j][i])
		{
			printf("%c", all->parse->map[j][i]);
			i++;
		}
		printf("\n");
		i = 0;
		j++;
	}
}

//Reads file, skips lines till map start

void	read_map(t_all *all)
{
	int	i;
	int	j;

	i = 0;
	while (i < all->parse->map_start)
	{
		all->parse->line = get_next_line(all->parse->fd_cub);
		free(all->parse->line);
		i++;
	}
	j = 0;
	while (i < all->parse->map_height + all->parse->map_start)
	{
		all->parse->line = get_next_line(all->parse->fd_cub);
		fill_row(all, j);
		free(all->parse->line);
		all->parse->line = NULL;
		i++;
		j++;
	}
	print_map(all);
}

//Reads one line and parses info into associated row in 2d array
//Parses player location as if ground but stores player coordinates

void	fill_row(t_all *all, int j)
{
	int	i;

	i = 0;
	while (i < all->parse->map_width)
	{
		if (i >= (int)ft_strlen(all->parse->line) - 1)
			all->parse->map[j][i] = space;
		else if (all->parse->line[i] == '1')
			all->parse->map[j][i] = wall;
		else if (all->parse->line[i] == '0')
			all->parse->map[j][i] = ground;
		else if (all->parse->line[i] == ' ')
			all->parse->map[j][i] = space;
		else
		{
			all->parse->map[j][i] = ground;
			all->parse->player_x = i;
			all->parse->player_y = j;
		}
		i++;
	}
}




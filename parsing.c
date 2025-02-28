/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vknape <vknape@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:06:42 by snijhuis          #+#    #+#             */
/*   Updated: 2025/01/16 14:46:43 by vknape           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

//Main function for handling parsing

void	parse(t_all *all, char **argv)
{
	all->parse->fd_cub = open(argv[1], O_RDONLY);
	if (all->parse->fd_cub == -1)
		clean_all(all, 0);
	printf("valid fd_cub\n");
	check_file(all);
	verify_map(all);
	// check_texture(all);
	// check_colour(all);
	if (close(all->parse->fd_cub) == -1)
		clean_all(all, 0);
	all->parse->fd_cub = open(argv[1], O_RDONLY);
	if (all->parse->fd_cub == -1)
		clean_all(all, 0);
	parse_map(all);
	if (close(all->parse->fd_cub) == -1)
		clean_all(all, 0);
	check_map_boundaries(all);
	all->parse->map[all->parse->player_y][all->parse->player_x] = all->parse->orientation;
}

//Iterates over each line in the file until all elements have been found
//or file ends. Stores any valid element and exits if no valid element,
//duplicate element or empty line has been found

void	check_file(t_all *all)
{
	all->parse->line = get_next_line(all->parse->fd_cub);
	while (all->parse->line && all->parse->count != 6)
	{
		all->parse->map_start++;
		if (check_element1(all) == 0)
			free(all->parse->line);
		all->parse->line = get_next_line(all->parse->fd_cub);
	}
	if (!all->parse->line)
		clean_all(all, 0);
	printf("count = %d\n", all->parse->count);
}

int	element_found(t_all *all)
{
	all->parse->count += 1;
	all->parse->line = NULL;
	return (1);
}

int	check_element1(t_all *all)
{
	if (ft_strncmp("NO ", all->parse->line, 3) == 0)
	{
		if (all->parse->north)
			clean_all(all, 1);
		all->parse->north = all->parse->line;
		return (element_found(all));
	}
	if (ft_strncmp("SO ", all->parse->line, 3) == 0)
	{
		if (all->parse->south)
			clean_all(all, 2);
		all->parse->south = all->parse->line;
		return (element_found(all));
	}
	if (ft_strncmp("WE ", all->parse->line, 3) == 0)
	{
		if (all->parse->west)
			clean_all(all, 3);
		all->parse->west = all->parse->line;
		return (element_found(all));
	}
	return (check_element2(all));
}

int	check_element2(t_all *all)
{
	if (ft_strncmp("EA ", all->parse->line, 3) == 0)
	{
		if (all->parse->east)
			clean_all(all, 4);
		all->parse->east = all->parse->line;
		return (element_found(all));
	}
	if (ft_strncmp("F ", all->parse->line, 2) == 0)
	{
		if (all->parse->floor)
			clean_all(all, 5);
		all->parse->floor = all->parse->line;
		return (element_found(all));
	}
	if (ft_strncmp("C ", all->parse->line, 2) == 0)
	{
		if (all->parse->ceiling)
			clean_all(all, 6);
		all->parse->ceiling = all->parse->line;
		return (element_found(all));
	}
	if (ft_strncmp("\n", all->parse->line, 2) != 0)
		clean_all(all, 7);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vknape <vknape@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:06:42 by snijhuis          #+#    #+#             */
/*   Updated: 2025/01/08 14:37:41 by vknape           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	parse(t_all *all, char **argv)
{
	all->parse->fd = open(argv[1], O_RDONLY);
	if (all->parse->fd == -1)
		clean_all(all);
	check_file(all);

}

void	check_file(t_all *all)
{
	all->parse->line = get_next_line(all->parse->fd);
	while (all->parse->line)
	{
		if (all->parse->count != 6 && check_element1 == 1)
			all->parse->line = NULL;
		free(all->parse->line);
		all->parse->line = get_next_line(all->parse->fd);
	}
}

int	check_element1(t_all *all)
{
	if (ft_strncmp("NO ./", all->parse->line, 5) == 0)
	{
		if (all->parse->north)
			clean_all(all);
		all->parse->north = all->parse->line;
		return (1);
	}
	if (ft_strncmp("SO ./", all->parse->line, 5) == 0)
	{
		if (all->parse->south)
			clean_all(all);
		all->parse->south = all->parse->line;
		return (1);
	}
	if (ft_strncmp("WE ./", all->parse->line, 5) == 0)
	{
		if (all->parse->west)
			clean_all(all);
		all->parse->west = all->parse->line;
		return (1);
	}
	return (check_element_other(all));
}

int	check_element2(t_all *all)
{
	if (ft_strncmp("EA ./", all->parse->line, 5) == 0)
	{
		if (all->parse->east)
			clean_all(all);
		all->parse->east = all->parse->line;
		return (1);
	}
	if (ft_strncmp("F ", all->parse->line, 5) == 0)
	{
		if (all->parse->floor)
			clean_all(all);
		all->parse->floor = all->parse->line;
		return (1);
	}
	if (ft_strncmp("C ", all->parse->line, 5) == 0)
	{
		if (all->parse->ceiling)
			clean_all(all);
		all->parse->ceiling = all->parse->line;
		return (1);
	}
	if (ft_strncmp("\t", all->parse->line, 2) != 0)
		clean_all(all);
}

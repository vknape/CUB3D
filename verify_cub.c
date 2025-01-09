/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   verify_cub.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: snijhuis <snijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/09 15:01:07 by snijhuis      #+#    #+#                 */
/*   Updated: 2025/01/09 15:35:17 by snijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	verify_map(t_all *all)
{
	while (all->parse->line)
	{
		if (ft_strncmp("\n", all->parse->line, 1) != 0)
		{
			check_invalid(all);
			all->parse->map_height++;
			if (all->parse->map_width < custom_strlen(all->parse->line))
				all->parse->map_width = custom_strlen(all->parse->line);
		}
		else if (all->parse->map_height > 0)
			clean_all(all, 9);
		else
			all->parse->map_start++;
		all->parse->line = get_next_line(all->parse->fd);
	}
	printf("map start %d\n", all->parse->map_start);
	printf("map height %d\n", all->parse->map_height);
	printf("map width: %d\n", all->parse->map_width);
}

void	check_invalid(t_all *all)
{
	int i;

	i = 0;
	while (all->parse->line[i])
	{
		if (!ft_strchr(" 01NSWE\n", all->parse->line[i]))
			clean_all(all, 8);
		if (all->parse->line[i] == 'N' || all->parse->line[i] == 'S'
			|| all->parse->line[i] == 'W' || all->parse->line[i] == 'E')
			all->parse->orientation = all->parse->line[i];
		i++;
	}
}
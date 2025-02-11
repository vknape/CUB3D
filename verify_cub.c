/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   verify_cub.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: vknape <vknape@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/09 15:01:07 by snijhuis      #+#    #+#                 */
/*   Updated: 2025/02/11 14:49:49 by snijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

//Calculate map width and height and check if the lines after the map
//are valid

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
		free(all->parse->line);
		all->parse->line = get_next_line(all->parse->fd_cub);
	}
	printf("map start %d\n", all->parse->map_start);
	printf("map height %d\n", all->parse->map_height);
	printf("map width: %d\n", all->parse->map_width);
}
//Check for invalid characters in map and save player orientation

void	check_invalid(t_all *all)
{
	int	i;

	i = 0;
	while (all->parse->line[i])
	{
		if (!ft_strchr(" 01NSWE\n", all->parse->line[i]))
			clean_all(all, 8);
		if (all->parse->line[i] == 'N' || all->parse->line[i] == 'S'
			|| all->parse->line[i] == 'W' || all->parse->line[i] == 'E')
		{
			if (all->parse->orientation != 0)
			{
				printf("wrong\n");
				clean_all(all, 0);
			}
			all->parse->orientation = all->parse->line[i];
		}
		i++;
	}
}

//Trims edges off texture path and tries loading to see if valid

void check_texture(t_all *all)
{
	trim_texture(all);
	all->texture->north = mlx_load_png(all->parse->north);
	if (!all->texture->north)
		clean_all(all, 12);
	all->texture->south = mlx_load_png(all->parse->south);
	if (!all->texture->south)
		clean_all(all, 12);
	all->texture->east = mlx_load_png(all->parse->east);
	if (!all->texture->east)
		clean_all(all, 12);
	all->texture->west = mlx_load_png(all->parse->west);
	if (!all->texture->west)
		clean_all(all, 12);

}


void trim_texture(t_all *all)
{
	char *temp;

	temp = all->parse->north;
	all->parse->north = ft_strtrim(all->parse->north + 2, " \n");
	free(temp);
	if (!all->parse->north)
		clean_all(all, 0);
	temp = all->parse->south;
	all->parse->south = ft_strtrim(all->parse->south + 2, " \n");
	free(temp);
	if (!all->parse->south)
		clean_all(all, 0);
	temp = all->parse->east;
	all->parse->east = ft_strtrim(all->parse->east + 2, " \n");
	free(temp);
	if (!all->parse->east)
		clean_all(all, 0);
	temp = all->parse->west;
	all->parse->west = ft_strtrim(all->parse->west + 2, " \n");
	free(temp);
	if (!all->parse->west)
		clean_all(all, 0);
}

void check_colour(t_all *all)
{
	char *temp;

	temp = all->parse->ceiling;
	all->parse->ceiling = ft_strtrim(all->parse->ceiling, "C \n");
	free(temp);	
	temp = all->parse->floor;
	all->parse->floor = ft_strtrim(all->parse->floor, "F \n");
	free(temp);
}

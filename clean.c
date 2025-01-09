/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   clean.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: snijhuis <snijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/07 14:25:38 by snijhuis      #+#    #+#                 */
/*   Updated: 2025/01/09 15:35:42 by snijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	clean_all(t_all *all, int status)
{
	printf("map height %d\n", all->parse->map_height);
	printf("map width: %d\n", all->parse->map_width);
	if (all->parse)
		free(all->parse);
	if (all->game)
		free(all->game);
	if (all)
		free(all);
	printf("exit %d\n", status);
	exit(status);
}
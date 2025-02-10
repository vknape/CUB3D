/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: vknape <vknape@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/06 13:43:26 by vknape        #+#    #+#                 */
/*   Updated: 2025/02/10 14:10:54 by snijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int argc, char **argv)
{
	t_all	*all;

	if (argc != 2)
		return (printf("Invalid amount of arguments, only 1 allowed."));
	init_struct(&all);
	parse(all, argv);
	start_game(all);
	clean_all(all, 0);
	return (0);
}

void	start_game(t_all *all)
{
	all->game->window = mlx_init(WINDOW_X, WINDOW_Y, "cub3D", 1);
	if (!all->game->window)
		clean_all(all, 0);
	all->game->img_width = all->parse->map_width * BLOCK;
	all->game->img_height = all->parse->map_height * BLOCK;
	all->game->image = mlx_new_image(all->game->window, all->game->img_width,
			all->game->img_height);
	load_textures(all);
	mlx_image_to_window(all->game->window, all->game->image, 0, 0);
	mlx_loop_hook(all->game->window, ft_hook, all);
	mlx_loop_hook(all->game->window, ft_keys, all);
	mlx_loop_hook(all->game->window, ft_raydir, all);
	mlx_loop(all->game->window);
	(void)all;
	return ;
}

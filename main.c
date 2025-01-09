/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: vknape <vknape@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/06 13:43:26 by vknape        #+#    #+#                 */
/*   Updated: 2025/01/09 15:35:29 by snijhuis      ########   odam.nl         */
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
	return (0);
}

void	ft_hook(void *param)
{
	t_all	*all;

	all = param;
	printf("%f\n", all->game->window->delta_time);
}

void	start_game(t_all *all)
{
	all->game->window = mlx_init(1024, 1024, "cub3D", 1);
	if (!all->game->window)
		clean_all(all, 0);
	// mlx_loop_hook(all->game->window, ft_hook, all);
	mlx_loop(all->game->window);
	(void)all;
	return ;
}

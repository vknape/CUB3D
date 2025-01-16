/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vknape <vknape@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 13:43:26 by vknape            #+#    #+#             */
/*   Updated: 2025/01/16 14:26:14 by vknape           ###   ########.fr       */
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

void	print_pixel(t_all *all, int i, int j)
{
	int	x;
	int	y;
	uint32_t color;

	if (all->parse->map[j][i] == space)
		color = 0x00000000;
	else if (all->parse->map[j][i] == ground)
		color = 0xFFFFFFFF;
	else if (all->parse->map[j][i] == wall)
		color = 0x000000FF;
	else
		color = 0xFF0000FF;
	x = 0;
	y = 0;
	while (y < 50)
	{
		while (x < 50)
		{
			mlx_put_pixel(all->game->image, i * 50 + x, j * 50 + y, color);
			x++;
		}
		x = 0;
		y++;
	}
}

void	ft_hook(void *param)
{
	t_all	*all;
	int	i;
	int	j;

	all = param;
	i = 0;
	j = 0;
	while (all->parse->map[j])
	{
		while (all->parse->map[j][i])
		{
			print_pixel(all, i, j);
			i++;
		}
		i = 0;
		j++;
	}
	// printf("%f\n", all->game->window->delta_time);
}

void	start_game(t_all *all)
{
	all->game->window = mlx_init(1920, 1080, "cub3D", 1);
	if (!all->game->window)
		clean_all(all, 0);
	all->game->image = mlx_new_image(all->game->window,
		all->parse->map_width * 50, all->parse->map_height * 50);
	mlx_image_to_window(all->game->window, all->game->image, 0, 0);
	mlx_loop_hook(all->game->window, ft_hook, all);
	mlx_loop(all->game->window);
	(void)all;
	return ;
}

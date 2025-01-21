/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vknape <vknape@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 13:43:26 by vknape            #+#    #+#             */
/*   Updated: 2025/01/20 16:02:56 by vknape           ###   ########.fr       */
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
	i = 0;
	j = 0;
	while (j < 25)
	{
		while (i < 25)
		{
			mlx_put_pixel(all->game->image, all->game->px + i, all->game->py + j, 0xFF0000FF);
			i++;
		}
		i = 0;
		j++;
	}
	// printf("%f\n", all->game->window->delta_time);
}

void	ft_keys(void *param)
{
	t_all *all;
	
	all = param;
	if (mlx_is_key_down(all->game->window, MLX_KEY_ESCAPE))
	{
		mlx_close_window(all->game->window);
		clean_all(all, 0);
	}
	if (mlx_is_key_down(all->game->window, MLX_KEY_W))
		all->game->py -= 5;
	if (mlx_is_key_down(all->game->window, MLX_KEY_S))
		all->game->py += 5;
	if (mlx_is_key_down(all->game->window, MLX_KEY_A))
		all->game->px -= 5;
	if (mlx_is_key_down(all->game->window, MLX_KEY_D))
		all->game->px += 5;
	if (mlx_is_key_down(all->game->window, MLX_KEY_LEFT))
		all->game->p_or += (pi / 180);
	if (mlx_is_key_down(all->game->window, MLX_KEY_RIGHT))
		all->game->p_or -= (pi / 180);
	if (all->game->py < 0)
		all->game->py = 0;
	if (all->game->py > all->game->img_height - 25)
		all->game->py = all->game->img_height - 25;
	if (all->game->px < 0)
		all->game->px = 0;
	if (all->game->px > all->game->img_width - 25)
		all->game->px = all->game->img_width - 25;
	while (all->game->p_or < 0)
		all->game->p_or += 2 * pi;
	if (all->game->p_or > 2 * pi)
		all->game->p_or = fmod(all->game->p_or, 2 * pi);
}

void	ft_raydir(void *param)
{
	t_all	*all;
	double	dir;
	int		i;
	
	all = param;
	dir = all->game->p_or - fov / 2;
	i = 0;
	while (i < 360)
	{
		dir += fov / 360;
		all->game->dirx = cos(dir);
		all->game->diry = -sin(dir);
		draw_ray(all);
		i++;
	}
	
}

void	draw_ray(t_all *all)
{
		int	i;
	double	x;
	double	y;

	// printf("%f\n", all->game->dirx);
	// printf("%f\n", all->game->diry);
	i = 0;
	while (i < 200)
	{
		// printf("%f\n", all->game->p_or);
		x = all->game->px + (all->game->dirx * i) + 12;
		y = all->game->py + (all->game->diry * i);
		// printf("%f\n", all->game->px);
		// printf("%f\n", all->game->py);
		// printf("%f\n", x);
		// printf("%f\n\n", y);
		if (!(x < 0 || x > all->game->img_width || y < 0 || y > all->game->img_height))
		// 	x = 0;
		// if (y < 0)
		// 	y = 0;
		// if (x > all->game->img_width)
		// 	x = all->game->img_width;
		// if (y > all->game->img_height)
		// 	y = all->game->img_height;
			mlx_put_pixel(all->game->image, x, y, 0xFF0000FF);
		// mlx_put_pixel(all->game->image, x + 1, y, 0xFF0000FF);
		// mlx_put_pixel(all->game->image, x + 2, y, 0xFF0000FF);
		i++;
	}
	// while (1)
	// ;
}

void	start_game(t_all *all)
{
	all->game->window = mlx_init(WINDOW_X, WINDOW_Y, "cub3D", 1);
	if (!all->game->window)
		clean_all(all, 0);
	all->game->img_width = all->parse->map_width * 50;
	all->game->img_height = all->parse->map_height * 50;
	all->game->image = mlx_new_image(all->game->window,
		all->game->img_width, all->game->img_height);
	mlx_image_to_window(all->game->window, all->game->image, 0, 0);
	mlx_loop_hook(all->game->window, ft_hook, all);
	mlx_loop_hook(all->game->window, ft_keys, all);
	mlx_loop_hook(all->game->window, ft_raydir, all);
	mlx_loop(all->game->window);
	(void)all;
	return ;
}

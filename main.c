/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vknape <vknape@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 13:43:26 by vknape            #+#    #+#             */
/*   Updated: 2025/02/27 11:06:00 by vknape           ###   ########.fr       */
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
	//test voor color convertion (moeten nog checken hoe we dit willen opslaan en waar we het willen doen):
	all->parse->hex_ceiling = color_to_hex(all, all->parse->ceiling);
	all->parse->hex_floor = color_to_hex(all, all->parse->floor);
	start_game(all);
	clean_all(all, 0);
	return (0);
}

uint32_t color_to_hex(t_all *all, char *color)
{
	char **temp;
	char **nums;
	uint32_t hex_color;

	temp = ft_split(color, ' ');
	if(!temp)
		clean_all(all, 0);
	nums = ft_split(temp[1], ',');
	if(!nums)
	{
		free_split(temp);
		clean_all(all, 0);
	}
	hex_color = (ft_atoi(nums[0]) << 24) | (ft_atoi(nums[1]) << 16) | (ft_atoi(nums[2]) << 8) | 255; //RGBA
	// hex_color = (ft_atoi(nums[0]) << 16) | (ft_atoi(nums[1]) << 8) | ft_atoi(nums[2]); //RGB
	free_split(temp);
	free_split(nums);
	return(hex_color);
}

void free_split (char **str)
{
	int i;

	i = 0;
	while(str[i])
	{
		free(str[i]);
		i ++;
	}
	free(str);
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
	all->print = true;
	mlx_image_to_window(all->game->window, all->game->image, 0, 0);
	mlx_loop_hook(all->game->window, ft_print, all);
	mlx_loop_hook(all->game->window, ft_keys, all);
	// mlx_key_hook(all->game->window, &my_keyhook, all);
	// mlx_loop_hook(all->game->window, ft_raydir, all);
	mlx_loop(all->game->window);
	return ;
}

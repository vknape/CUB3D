/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: vknape <vknape@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/09 13:00:10 by snijhuis      #+#    #+#                 */
/*   Updated: 2025/01/21 15:44:07 by snijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// Calculates the length of the string, excluding spaces at the end

int	custom_strlen(char *str)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		if (ft_isprint(str[i]))
			count = i;
		i++;
	}
	return (count + 1);
}

void	ft_keys(void *param)
{
	t_all	*all;

	all = param;
	if (mlx_is_key_down(all->game->window, MLX_KEY_ESCAPE))
	{
		mlx_close_window(all->game->window);
		clean_all(all, 0);
	}
	if (mlx_is_key_down(all->game->window, MLX_KEY_W))
	{
		all->game->py -= 5.0 / BLOCK;
		wall_collision(all, 'W');
	}
	if (mlx_is_key_down(all->game->window, MLX_KEY_S))
	{
		all->game->py += 5.0 / BLOCK;
		wall_collision(all, 'S');
	}
	if (mlx_is_key_down(all->game->window, MLX_KEY_A))
	{
		all->game->px -= 5.0 / BLOCK;
		wall_collision(all, 'A');
	}
	if (mlx_is_key_down(all->game->window, MLX_KEY_D))
	{
		all->game->px += 5.0 / BLOCK;
		wall_collision(all, 'D');
	}
	if (mlx_is_key_down(all->game->window, MLX_KEY_LEFT))
		all->game->p_or += (pi / 90);
	if (mlx_is_key_down(all->game->window, MLX_KEY_RIGHT))
		all->game->p_or -= (pi / 90);

	
		//kan eruit
	if (all->game->py < 0)
		all->game->py = 0;
	if (all->game->py > all->parse->map_height)
		all->game->py = all->parse->map_height - BLOCK / 100;
	if (all->game->px < 0)
		all->game->px = 0;
	if (all->game->px > all->parse->map_width)
		all->game->px = all->parse->map_width - BLOCK / 100;
	while (all->game->p_or < 0)
		all->game->p_or += 2 * pi;
	if (all->game->p_or > 2 * pi)
		all->game->p_or = fmod(all->game->p_or, 2 * pi);
}
void wall_collision(t_all *all, char or)
{
	if (or == 'W' && all->parse->map[(int)floor(all->game->py)][(int)floor(all->game->px)] == wall)
	{
		// printf("yw = %d\n", y);
		all->game->py = ceil(all->game->py);
	}
	if (or == 'S' && all->parse->map[(int)ceil(all->game->py)][(int)floor(all->game->px)] == wall)
	{
		// printf("yw = %d\n", y);
		all->game->py = ceil(all->game->py);
	}



// 	if (or == 'S' && all->parse->map[y][x - 1] == wall)
// 	{
// 		// printf("ys = %d\n", y);
// 		all->game->py = y * 50 - 50;
// 		if (temp <= 25)
// 			all->game->py += temp;
// 		else
// 			all->game->py += 25;
// 	}
// 	// if (or == 'A')
// 	// 	all->game->px = x * 50;
// 	// if(or == 'D')
// 	// 	all->game->px = x * 50 - 25;
}


// void	wall_collision(t_all *all, char or)
// {
// 	int x;
// 	int y;
// 	int temp;

// 	temp = all->game->px;
// 	x = 1;
// 	y = 1;
	
// 	while(temp >= 50)
// 	{
// 		temp -= 50;
// 		x ++;
// 	}
// 	// all->game->px -= temp;
// 	temp = all->game->py;
// 	while (temp >= 50)
// 	{
// 		temp -= 50;
// 		y ++;
// 	}
// 	// all->game->py -= temp;

// 	printf("yw = %d\n", y);
// 	printf("temp = %d", temp);
// 	// printf("ys = %d\n\n", y);
	
// 	if (or == 'W' && all->parse->map[y - 1][x - 1] == wall)
// 	{
// 		// printf("yw = %d\n", y);
// 		all->game->py = y * 50;
// 	}
// 	if (or == 'S' && all->parse->map[y][x - 1] == wall)
// 	{
// 		// printf("ys = %d\n", y);
// 		all->game->py = y * 50 - 50;
// 		if (temp <= 25)
// 			all->game->py += temp;
// 		else
// 			all->game->py += 25;
// 	}
// 	// if (or == 'A')
// 	// 	all->game->px = x * 50;
// 	// if(or == 'D')
// 	// 	all->game->px = x * 50 - 25;

// 	return ;
// }

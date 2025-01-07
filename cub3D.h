/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3D.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: vknape <vknape@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/06 13:50:55 by vknape        #+#    #+#                 */
/*   Updated: 2025/01/07 14:50:15 by snijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "MLX42/include/MLX42/MLX42.h"
# include "libft/libft.h"
# include <math.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_game
{
    mlx_t   *window;
}           t_game;

typedef struct s_parse
{

}			t_parse;

typedef struct s_all
{
    int     status;
    t_parse *parse;
    t_game  *game;
}			t_all;

void init_struct(t_all **all);
void clean_all(t_all *all);
void start_game(t_all *all);

#endif
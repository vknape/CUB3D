/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3D.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: vknape <vknape@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/06 13:50:55 by vknape        #+#    #+#                 */
/*   Updated: 2025/01/09 15:32:31 by snijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "MLX42/include/MLX42/MLX42.h"
# include "libft/libft.h"
# include "get_next_line.h"
# include <math.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_game
{
    mlx_t   *window;
}           t_game;

typedef struct s_parse
{
    int     fd;
    char    *line;
    int     count;
    int     player_count;
    char    *north;
    char    *south;
    char    *west;
    char    *east;
    char    *floor;
    char    *ceiling;
    int     map_width;
    int     map_height;
    char    orientation;
    char    **map;
    int     map_start;
    
}			t_parse;

typedef struct s_all
{
    int     status;
    t_parse *parse;
    t_game  *game;
}			t_all;

void init_struct(t_all **all);
void clean_all(t_all *all, int status);
void start_game(t_all *all);
void parse(t_all *all, char **argv);
void check_file(t_all *all);
int  check_element1(t_all *all);
int  check_element2(t_all *all);
int element_found(t_all *all);
void    verify_map(t_all *all);
int	custom_strlen(char *str);
void	check_invalid(t_all *all);
void parse_map(t_all *all);

#endif
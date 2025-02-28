/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vknape <vknape@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 13:50:55 by vknape            #+#    #+#             */
/*   Updated: 2025/01/16 13:42:22 by vknape           ###   ########.fr       */
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

enum e_elem
{
    wall = '1',
    ground = '0',
    space = '_'
};


typedef struct s_game
{
    mlx_t   *window;
    mlx_image_t *image;
    mlx_texture_t *north;
    mlx_texture_t *south;
    mlx_texture_t *west;
    mlx_texture_t *east;
}           t_game;

typedef struct s_parse
{
    int     fd_cub;
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
    int     player_x;
    int     player_y;
    
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
void    read_map(t_all *all);
void    fill_row(t_all *all, int j);
void    check_map_boundaries(t_all *all);
void	check_map_row(t_all *all, int j);
void	check_map_column(t_all *all, int i);
void	clean_parse(t_all *all);
void	empty_buffer(t_all *all);
void    check_colour(t_all *all);
void    check_texture(t_all *all);
void trim_texture(t_all *all);


#endif
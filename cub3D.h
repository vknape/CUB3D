/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3D.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: vknape <vknape@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/06 13:50:55 by vknape        #+#    #+#                 */
/*   Updated: 2025/02/25 17:01:09 by snijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "MLX42/include/MLX42/MLX42.h"
# include "get_next_line.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <unistd.h>

# define WINDOW_X 1920
# define WINDOW_Y 1080
# define pi 3.141592653589793
# define fov pi / 2.0
# define BLOCK 64.0
# define STEP 5.0 / BLOCK
# define MINI_BLOCK 24.0
# define MINI_LIMITS 15

enum				e_elem
{
	wall = '1',
	ground = '0',
	space = '_'
};

typedef struct s_game
{
	mlx_t			*window;
	mlx_image_t		*image;
	int				img_width;
	int				img_height;
	double			px;
	double			py;
	double			p_or;
	double			dirx;
	double			diry;
	
}					t_game;

typedef struct s_parse
{
	int				fd_cub;
	char			*line;
	int				count;
	int				player_count;
	char			*north;
	char			*south;
	char			*west;
	char			*east;
	char			*floor;
	char			*ceiling;
	uint32_t		hex_floor;
	uint32_t		hex_ceiling;
	int				map_width;
	int				map_height;
	char			orientation;
	char			**map;
	int				map_start;
	int				player_x;
	int				player_y;

}					t_parse;

typedef struct s_ray
{
	double	ray_x;
	double	ray_y;
	double 	calc_x;
	double  calc_y;
	double  calc_or;
	double 	calc_ray;
	double	ray_length;
	double	wall_height;
	double	wall_top;
	double	wall_bottom;
	bool	valid_ray;
	bool	xneg;
	bool	yneg;
	mlx_texture_t	*texture;
	char	axis;
}			t_ray;

typedef struct s_texture
{
	mlx_texture_t	*north;
	mlx_texture_t	*south;
	mlx_texture_t	*west;
	mlx_texture_t	*east;
    double north_scale_h;
    double north_scale_w;
    double south_scale_h;
    double south_scale_w;
    double east_scale_h;
    double east_scale_w;
    double west_scale_h;
    double west_scale_w;
} t_texture;


typedef struct s_all
{
	int				status;
	bool			print;
	t_parse			*parse;
	t_game			*game;
	t_ray			*ray;
	t_texture		*texture;
}					t_all;

void				init_struct(t_all **all);
void				clean_all(t_all *all, int status);
void				start_game(t_all *all);
void				parse(t_all *all, char **argv);
void				check_file(t_all *all);
int					check_element1(t_all *all);
int					check_element2(t_all *all);
int					element_found(t_all *all);
void				verify_map(t_all *all);
int					custom_strlen(char *str);
void				check_invalid(t_all *all);
void				parse_map(t_all *all);
void				read_map(t_all *all);
void				fill_row(t_all *all, int j);
void				check_map_boundaries(t_all *all);
void				check_map_row(t_all *all, int j);
void				check_map_column(t_all *all, int i);
void				clean_parse(t_all *all);
void				empty_buffer(t_all *all);
void				check_colour(t_all *all);
void				check_texture(t_all *all);
void				trim_texture(t_all *all);
void				draw_ray(t_all *all);
void				ft_raydir(t_all *all);
void				ft_keys(void *param);
void				my_keyhook(mlx_key_data_t keydata, void *param);
void				ft_print(void *param);
void				wall_collision(t_all *all);
void				ray_end_xpos(t_all *all);
void				ray_end_ypos(t_all *all);
void				calculate_ray(t_all *all);
void				assign_ray(t_all *all, int id, char axis);
void 				ray_xpos_loop (t_all *all);
void				ray_ypos_loop (t_all *all);
void				render_line(t_all *all, int i, double dir);
void 				load_textures (t_all *all);
void				scale_texture (t_all *all);
uint32_t			texture_color(t_all *all, int tex_y);
void				clean_texture(t_all *all);
void				clean_game(t_all *all);
void				substr_textures(t_all *all);
void				print_background(t_all *all);
void				print_player(t_all *all);
void				print_mini_map(t_all *all, int i, int j, int offset_i, int offset_j);
uint32_t			color_mini(t_all *all, int i, int j, int offset_i, int offset_j);
uint32_t			color_to_hex(t_all *all, char *color);
void				free_split (char **str);


#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 15:39:29 by jcauchet          #+#    #+#             */
/*   Updated: 2022/09/14 15:41:43 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

# define CUB3D_H

# define ERROR -1
# define C 42
# define R 43
# define NO 44
# define SO 45
# define EA 46
# define WE 47

# define PXL 0x0055FFFF
# define WIDTH 1600
# define HEIGHT 900

# define SPACES "\033[1;31mError: spaces between params are forbidden\n\033[0m"
# define ARGS "\033[1;31mError: please use a correct format.\n\033[0m"
# define FD "\033[1;31mError: cannot open FD.\n\033[0m"
# define M_PARAM "\033[1;31mError: some parameters are missing.\n\033[0m"
# define M_VAL "\033[1;31mError: map params must have a value.\n\033[0m"
# define COMMAS "\033[1;31mError: number of commas is not correct.\n\033[0m"
# define RGB_INT "\033[1;31mError: ceiling and floor must be integers.\n\033[0m"
# define RGB_F "\033[1;31mError: ceiling and floor must have RGB format.\n\033[0m"
# define RGB_R "\033[1;31mError: RGB values must be in [0, 255] range.\n\033[0m"
# define PARAM "\033[1;31mError: map parameters syntax is not correct.\n\033[0m"
# define MAP "\033[1;31mError: map description syntax is not correct.\n\033[0m"
# define PLY "\033[1;31mError: only one player is allowed in the map.\n\033[0m"
# define NO_MAP "\033[1;31mError: map description is missing.\n\033[0m"
# define EMPTY "\033[1;31mError: empty lines are not allowed in the map.\n\033[0m"
# define WALLS "\033[1;31mError: map should be surrounded by walls.\n\033[0m"
# define DUP "\033[1;31mError: duplicated map parameters.\n\033[0m"
# define CHARS "\033[1;31mError: map contains forbidden characters.\n\033[0m"
# define CUB "\033[1;31mError: map file name must end with .cub.\n\033[0m"
# define XPM "\033[1;31mError: texture file name name must end with .xpm\n\033[0m"

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h> 
# include <float.h>
# include <unistd.h>
# include <math.h>
# include "../srcs/minilibx/mlx.h"
# include "../srcs/minilibx/mlx_opengl.h"
# include "../srcs/minilibx/mlx_png.h"
# include "../srcs/gnl/get_next_line.h"
# include "../srcs/libft/libft.h"

typedef struct params
{
	int		*c;
	int		*f;
	char	*no;
	char	*so;
	char	*ea;
	char	*we;
}	t_p;

typedef struct win
{
	void	*img_data;
	void	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_win;

typedef struct mlx
{
	void	*ptr;
	void	*win;
	t_win	img;
}	t_mlx;

typedef struct data
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	time;
	double	old_time;
	double	cam_x;
	double	ray_dir_x;
	double	ray_dir_y;
	double	s_dist_x;
	double	s_dist_y;
	double	delta_x;
	double	delta_y;
	double	wall_dist;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_h;
	int		draw_start;
	int		draw_end;
	
}	t_d;

// Parsing functions

char	**parsing(char *map, t_p *params, char **tab);
void	free_tab(char **tab);
int		param_error(char *map, t_p *params);
void	exit_and_print(char *str);
void	check_commas_num(char *str, int i);
char	*char_param(char *name, char *str, int i, void *ptr);
char	**map_error(char **tab, int fd, t_p *params);
void	check_h_space(char *tab);
void	check_h_zero(char *tab);
char	**resize_tab(char **tab);
void	check_v_space(char **tab);
void	check_v_zero(char **tab);
void	print_tab(char **tab);
void	check_xpm(t_p *params, int i);
int		end_with_spaces(char *str);
char	**check_walls(char **tab, t_p *params);
int		tab_size(char **tab);

// Raycasting functions

void	raycasting(char **tab, t_p params);
void	ft_pixel_put(t_win *img, int x, int y, int color);
void	init_data(char **tab, t_d *data);
char	**remove_spaces(char **tab);

#endif

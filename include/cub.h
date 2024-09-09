/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 13:07:18 by rofuente          #+#    #+#             */
/*   Updated: 2024/09/09 13:58:49 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

/* ---------- LIBRERIAS ---------- */
# include "../libft/include/libft.h"
# include "../libft/ft_printf/include/ft_printf.h"
# include "../libft/gnl/include/get_next_line.h"
# include "../mlx/mlx.h"
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <errno.h>
# include <math.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <limits.h>
# include <fcntl.h>
# include <X11/keysym.h>
# include <X11/X.h>

/* ---------- TECLAS ---------- */
# define KEY_ESC		65307
# define KEY_W		119
# define KEY_A		97
# define KEY_S		115
# define KEY_D		100
# define ARROW_LEFT	65361
# define ARROW_RIGHT	65363
# define SPACE		32
# define PI 3.14159264
# define DESTROY		17
# define XPM_PATH		"./xpm/"
# define WIDTH 1920
# define HEIGHT 1080
# define TEXTURE_WIDTH 32
# define TEXTURE_HEIGHT 32
# define SPEED			0.09
# define ROTATION		0.09

# ifndef O_DIRECTORY
#  define O_DIRECTORY 00200000
# endif

/* ---------- STRUCTS ---------- */
typedef struct s_intvec
{
	int	x;
	int	y;
}	t_intvec;

typedef struct s_vec
{
	double	x;
	double	y;
}	t_vec;

typedef struct s_ray
{
	int			side;
	int			line_start;
	int			line_end;
	double		cam_x;
	double		perpwalldist;
	double		wall_x;
	double		tex_pos;
	double		tex_step;
	t_intvec	pos;
	t_intvec	step;
	t_intvec	tex;
	t_vec		dir;
	t_vec		delta_dist;
	t_vec		side_dist;
}	t_ray;

typedef struct s_img
{
	void	*img;
	void	*ptr;
	int		w;
	int		h;
	int		bpp;
	int		size_line;
	int		endian;
}	t_img;

typedef struct s_player
{
	char	point;
	float	fov;
	t_vec	pos;
	t_vec	dir;
	t_vec	plane;
}	t_player;

typedef struct s_texture
{
	char	*n;
	char	*s;
	char	*e;
	char	*w;
	char	**f;
	char	**c;
}	t_texture;

typedef struct s_map
{
	int		lines;
	int		fd;
	char	**map_cpy;
	float	scale;
	int		color;
}	t_map;

typedef struct s_game
{
	int			map_height;
	int			map_width;
	void		*mlx;
	void		*win;
	char		**map;
	char		**dmap;
	t_map		map_data;
	t_texture	tex;
	t_player	pc;
	t_img		img[5];
	t_ray		ray;
	t_vec		mouse_pos;
}	t_game;

/* ---------- FUNCIONES ---------- */

/* ----- SRC ----- */
/* FT_CUB.C */
void	clean_game(t_game *game);
void	ft_error(t_game *game, char *error);

/* FT_PARSE.C */
int		parse(t_game *game, char **argv);

/* FT_PARSE_UTILS.C */
void	copy_map(t_game *game, char **file, int start);
void	copy_info(t_game *game, char *line, int j);
void	fill_copy(t_game *game);
int		count_lines(char *file);

/* FT_PARSE_UTILS_1.C */
void	copy_colors(t_game *game, char *line, int j);
void	copy_textures(t_game *game, char *line, int j);
int		count_map_height(char **file, int i);

/* FT_INITIALIZE.C */
void	init_img(t_game *game);
void	init_cameraplane(t_game *game);
void	init_player(t_game *game);
void	init_data(t_game *game);

/* FT_RENDER.C */
void	put_pixel(t_game *game, int x, int y, int color);
void	render_background(t_game *game);
int		render(t_game *game);

/* FT_KEY.C */
int		key_event(int key, t_game *game);
void	mouse_move(t_game *game);

/* FT_UTILS.C */
void	print_info(t_game *game);
void	print_array(char **array);
void	free_info(t_game *game);
void	free_array(char **array);
char	*ft_strdup_no_nl(char *str);

/* FT_UTILS_1.C */
void	destroy_images(t_game *game);
int		close_window(t_game *game);
int		number_to_hex(char **number);
void	duplicate_map(t_game *game);
void	floodfill(char **map_dup, int x, int y);

/* FT_CHECKER.C */
int		info_validity(t_texture textures);

/* FT_MAP_CHECKER.C */
int		map_validity(t_game *game);

/* FT_RAYCASTING.C */
void	raycasting(t_game *game);

/* FT_RAYCASTING_UTILS.C */
void	draw_vline(t_game *game, int x);

/* FT_MINIMAP.C */
int	put_minimap(t_game *game);

/* ---------- COLOR FONT ---------- */
# define RED     "\x1b[31m"
# define GREEN   "\x1b[32m"
# define RESET   "\x1b[0m"

#endif

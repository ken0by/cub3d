/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ken0by <ken0by@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 13:07:18 by rofuente          #+#    #+#             */
/*   Updated: 2024/09/16 11:23:14 by ken0by           ###   ########.fr       */
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
# define WIDTH 1280
# define HEIGHT 720
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
	float		scale;
	void		*mlx;
	void		*win;
	char		**map;
	char		**dmap;
	t_map		map_data;
	t_texture	tex;
	t_player	pc;
	t_img		img[5];
	t_img		m_map;
	t_ray		ray;
	t_vec		mouse_pos;
}	t_game;

/* ---------- FUNCIONES ---------- */

/* ----- SRC ----- */
/* FT_CUB.C */
void	ft_clean_game(t_game *game);
void	ft_error(t_game *game, char *error);

/* FT_PARSE.C */
int		ft_parse(t_game *game, char **argv);

/* FT_PARSE_UTILS.C */
void	ft_cpy_map(t_game *game, char **file, int start);
void	ft_info(t_game *game, char *line, int j);
void	ft_cpy(t_game *game);
int		ft_count(char *file);

/* FT_PARSE_UTILS_1.C */
void	ft_colors(t_game *game, char *line, int j);
void	ft_textures(t_game *game, char *line, int j);
int		ft_map_height(char **file, int i);

/* FT_INITIALIZE.C */
void	ft_img(t_game *game);
void	ft_camerap(t_game *game);
void	ft_player(t_game *game);
void	ft_data(t_game *game);

/* FT_RENDER.C */
void	ft_pixel(t_game *game, int x, int y, int color);
void	ft_background(t_game *game);
int		ft_render(t_game *game);

/* FT_KEY.C */
int		ft_key(int key, t_game *game);
void	ft_mouse_move(t_game *game);

/* FT_UTILS.C */
void	ft_print_inf(t_game *game);
void	ft_print_arr(char **array);
void	ft_free_inf(t_game *game);
void	ft_free_arr(char **array);
char	*ft_strdup_nl(char *str);

/* FT_UTILS_1.C */
void	ft_destroy(t_game *game);
int		ft_close(t_game *game);
int		ft_nb_to_hex(char **number);
void	ft_dmap(t_game *game);
void	ft_floodfill(char **map_dup, int x, int y);

/* FT_CHECKER.C */
int		ft_check_inf(t_texture textures);

/* FT_MAP_CHECKER.C */
int		ft_map_check(t_game *game);

/* FT_RAYCASTING.C */
void	ft_raycasting(t_game *game);

/* FT_RAYCASTING_UTILS.C */
void	ft_draw(t_game *game, int x);

/* FT_MINIMAP.C */
void	ft_pixel2(t_game *game, int x, int y, int color);
int		ft_minimap(t_game *game);

/* FT_MINIMAP_UTILS.C */
int		ft_trgb(int t, int r, int g, int b);
void	ft_line(t_game *game, t_vec vect, t_map map);
void	ft_circle(t_game *game, t_vec vect, int radius, t_map map);
void	ft_scaled_pixel(t_game *game, int x, int y, t_map map);

/* FT_MINIMAP_UTILS1.C */
t_vec	ft_norm_vect(t_vec v1);

/* ---------- COLOR FONT ---------- */
# define RED     "\x1b[31m"
# define GREEN   "\x1b[32m"
# define RESET   "\x1b[0m"

#endif

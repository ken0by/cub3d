/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 13:07:18 by rofuente          #+#    #+#             */
/*   Updated: 2024/07/22 13:28:55 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

/* ---------- LIBRERIAS ---------- */
# include "../libft/include/libft.h"
# include "../libft/ft_printf/include/ft_printf.h"
# include "../libft/gnl/include/get_next_line.h"
# include "../mlx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <math.h>

/* ---------- TECLAS ---------- */
# define KEY_ESC		65307
# define KEY_W		119
# define KEY_A		97
# define KEY_S		115
# define KEY_D		100
# define ARROW_LEFT	65361
# define ARROW_RIGHT	65363
# define SPACE		65
# define FOV 0.392699081
# define PI 3.141592653589793238

# define DESTROY		17
# define XPM_PATH		"./xpm/"

# define WIN_WIDTH 1350
# define WIN_HEIGHT 850

/* ---------- STRUCTS ---------- */
typedef struct s_rgb{
	int	r;
	int	g;
	int	b;
}	t_rgb;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		bpp;
	int		size_line;
	int		endian;
}	t_img;

typedef struct s_map{
	int		height;
	int		width;
	char	**cpy;
	char	**map;
	char	*nroute;
	char	*sroute;
	char	*eroute;
	char	*wroute;
	void	*north;
	void	*south;
	void	*east;
	void	*west;
	t_rgb	floor;
	t_rgb	ceiling;
}	t_map;

typedef struct s_vec{
	int	x;
	int	y;
}	t_vec;

typedef struct s_player{
	double	x;
	double	y;
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;
	double	cameraX;
	double	rayDirX;
	double	rayDirY;
	double	sideDistX;
	double	sideDistY;
	double	perpWallDist;
	double	deltaDistX;
	double	deltaDistY;
	int		mapX;
	int		mapY;
	int		stepX;
	int		stepY;
	int		hit;
	int		side;
	int		lineHeight;
	int		drawStart;
	int		drawEnd;
	int		color;
	char	flag;
}	t_player;

typedef struct s_game
{
	int			img_height;
	int			img_width;
	int			bitpp;
	int			line_len;
	int			endian;
	int			f_color;
	int			c_color;
	int			*ads;
	char		*data;
	void		*mlx;
	void		*win;
	void		*address;
	t_map		map;
	t_img		img;
	t_img		floor;
	t_img		ceiling;
	t_img		color;
	t_img		img_data;
	t_img		n_img;
	t_img		s_img;
	t_img		e_img;
	t_img		w_img;
	t_player	player;
	t_vec		pos;
	t_vec		direction;
}	t_game;

/* ---------- FUNCIONES ---------- */

/* ----- SRC ----- */
/* FT_CUB.C */
void	ft_error(char *s);

/* FT_READ_MAP.C */
void	ft_read_map(t_game *game, char *file);

/* FT_CHECK_MAP.C */
void	ft_check_map(t_game *game);

/* FT_START_XPM.C */
void	all_xpm(t_game *game);
void	print_img(t_game *game, void *img, int i, int j);

/* FT_PLAYER.C */
int		ft_player(void *param);

/* FT_INIT_PLAYER.C */
void	ft_dir_n(t_game *game);
void	ft_dir_s(t_game *game);
void	ft_dir_e(t_game *game);
void	ft_dir_w(t_game *game);

/* FT_KEY.C */
int		ft_key(int key, t_game *game);

/* ----- UTILS ----- */
/* FT_NO_NL.C*/
char	*ft_strjoin_no_nl(char *s1, char *s2);
char	*ft_strdup_no_nl(char *s);

/* FT_SLEN.C */
int		ft_slen(char *s);

/* FREEZER.C */
void	ft_free_mtx(char **mtx);

/* ---------- COLOR FONT ---------- */
# define RED     "\x1b[31m"
# define GREEN   "\x1b[32m"
# define RESET   "\x1b[0m"

#endif

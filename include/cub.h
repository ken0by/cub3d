/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 13:07:18 by rofuente          #+#    #+#             */
/*   Updated: 2024/06/18 16:44:00 by rofuente         ###   ########.fr       */
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

/* ---------- TECLAS ---------- */
# define KEY_ESC		65307
# define KEY_W			119
# define KEY_A			97
# define KEY_S			115
# define KEY_D			100

# define KEY_UP			126
# define ARROW_LEFT		65361
# define ARROW_RIGHT	65363

# define DESTROY		17
# define XPM_PATH		"./xpm/"

/* ---------- STRUCTS ---------- */
typedef struct s_rgb{
	int	r;
	int	g;
	int	b;
}	t_rgb;

typedef struct s_vector
{
	double	x;
	double	y;
}	t_vector;

typedef struct s_img
{
	void	*ptr;
	int		*data;
	int		bits;
	int		len;
	int		endian;
	int		h;
	int		w;
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

typedef struct s_game
{
	int		img_height;
	int		img_width;
	int		bitpp;
	int		line_len;
	int		endian;
	int		f_color;
	int		c_color;
	void	*mlx;
	void	*win;
	void	*img;
	void	*address;
	t_map	map;
	t_img	img_data;
	t_img	n_img;
	t_img	s_img;
	t_img	e_img;
	t_img	w_img;
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

/* ----- UTILS ----- */
/* FT_NO_NL.C*/
char	*ft_strjoin_no_nl(char *s1, char *s2);
char	*ft_strdup_no_nl(char *s);

/* FT_SLEN.C */
int		ft_slen(char *s);

/* ---------- COLOR FONT ---------- */
# define RED     "\x1b[31m"
# define GREEN   "\x1b[32m"
# define RESET   "\x1b[0m"

#endif

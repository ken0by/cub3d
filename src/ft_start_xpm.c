/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_xpm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ken0by <ken0by@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 13:47:40 by rofuente          #+#    #+#             */
/*   Updated: 2024/06/26 21:39:25 by ken0by           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

static void	ft_color(t_game *game)
{
	int	x;
	int	y;

	x = -1;
	while (game->map.map[++x])
	{
		y = -1;
		while (game->map.map[x][++y])
		{
			if (game->map.map[x][y] == 'N')
			{
				game->color = game->n_img;
				break ;
			}
			if (game->map.map[x][y] == 'S')
			{
				game->color = game->s_img;
				break ;
			}
			if (game->map.map[x][y] == 'E')
			{
				game->color = game->e_img;
				break ;
			}
			if (game->map.map[x][y] == 'W')
			{
				game->color = game->w_img;
				break ;
			}
		}
	}
}

static int	ft_rgb_color(int t, int r, int g, int b) {
	return (t << 24 | r << 16 | g << 8 | b);
}

static t_img	start_xpm(t_game *game, char *str)
{
	game->img_data.img = mlx_xpm_file_to_image(game->mlx, str,
			&game->img_width, &game->img_height);
	if (game->img_data.img == NULL)
		ft_error("XPM to image fail!\n");
	game->img_data.data = (int *)mlx_get_data_addr(game->img_data.img,
			&game->bitpp, &game->line_len, &game->img_data.endian);
	return (game->img_data);
}

void	all_xpm(t_game *game)
{
	game->n_img = start_xpm(game,game->map.nroute);
	game->s_img = start_xpm(game,game->map.sroute);
	game->e_img = start_xpm(game,game->map.eroute);
	game->w_img = start_xpm(game,game->map.wroute);
	game->f_color = ft_rgb_color(0, game->map.floor.r, game->map.floor.g, game->map.floor.b);
	game->c_color = ft_rgb_color(0, game->map.ceiling.r, game->map.ceiling.g, game->map.ceiling.b);
	ft_color(game);
}

void	print_img(t_game *game, void *img, int i, int j)
{
	mlx_put_image_to_window(game->mlx, game->win, img, i, j);
}

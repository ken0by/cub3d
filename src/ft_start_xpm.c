/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_xpm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 13:47:40 by rofuente          #+#    #+#             */
/*   Updated: 2024/06/18 16:52:05 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

static void prueba_color(t_game *game)
{
	for (int y = 0; y < 1920; y++)
	{
		for (int x = 0; x < 1080; x++)
			mlx_pixel_put(game->mlx, game->win, x, y, game->f_color);
	}
}

static int	ft_rgb_color(int t, int r, int g, int b) {
	return (t << 24 | r << 16 | g << 8 | b);
}

static t_img	start_xpm(t_game *game, char *str)
{
	game->img_data.ptr = mlx_xpm_file_to_image(game->mlx, str,
			&game->img_width, &game->img_height);
	if (game->img_data.ptr == NULL)
		ft_error("XPM to image fail!\n");
	game->img_data.data = (int *)mlx_get_data_addr(game->img_data.ptr,
			&game->img_data.bits, &game->img_data.len, &game->img_data.endian);
	if (!game->img_data.data)
		ft_error("XPM data fail!\n");
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
	prueba_color(game);
}

void	print_img(t_game *game, void *img, int i, int j)
{
	mlx_put_image_to_window(game->mlx, game->win, img, i, j);
}

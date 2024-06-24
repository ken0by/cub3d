/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_xpm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 13:47:40 by rofuente          #+#    #+#             */
/*   Updated: 2024/06/24 18:05:43 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

/* static void	ft_color(t_game *game)
{
	for (int y = 0; y < WIN_WIDTH; y++) {
		for (int x = 0; x < WIN_HEIGHT; x++) {
			int pixel = (y * game->line_len) + (x * (game->bitpp / 8));
			game->data[pixel + 0] = (game->f_color >> 0) & 0xFF; // Blue
			game->data[pixel + 1] = (game->f_color >> 8) & 0xFF; // Green
			game->data[pixel + 2] = (game->f_color >> 16) & 0xFF; // Red
			game->data[pixel + 3] = (game->f_color >> 24) & 0xFF; // Alpha
		}
	}
} */

static int	ft_rgb_color(int t, int r, int g, int b) {
	return (t << 24 | r << 16 | g << 8 | b);
}

static t_img	start_xpm(t_game *game, char *str)
{
	game->img_data.ptr = mlx_xpm_file_to_image(game->mlx, str,
			&game->img_width, &game->img_height);
	if (game->img_data.ptr == NULL)
		ft_error("XPM to image fail!\n");
	game->img_data.img_data = mlx_get_data_addr(game->img_data.ptr,
			&game->bitpp, &game->line_len, &game->img_data.endian);
	if (!game->img_data.img_data)
		ft_error("XPM data fail!\n");
	return (game->img_data);
}

void	all_xpm(t_game *game)
{
	game->n_img = start_xpm(game,game->map.nroute);
	game->s_img = start_xpm(game,game->map.sroute);
	game->e_img = start_xpm(game,game->map.eroute);
	game->w_img = start_xpm(game,game->map.wroute);
	//game->data = mlx_get_data_addr(game->img, &game->bitpp, &game->line_len, &game->endian);
	game->f_color = ft_rgb_color(0, game->map.floor.r, game->map.floor.g, game->map.floor.b);
	game->c_color = ft_rgb_color(0, game->map.ceiling.r, game->map.ceiling.g, game->map.ceiling.b);
	//ft_color(game);
	//print_img(game, game->img, 0, 0);
}

void	print_img(t_game *game, void *img, int i, int j)
{
	mlx_put_image_to_window(game->mlx, game->win, img, i, j);
}

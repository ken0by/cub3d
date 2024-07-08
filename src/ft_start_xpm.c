/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_xpm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 13:47:40 by rofuente          #+#    #+#             */
/*   Updated: 2024/07/08 11:37:40 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

static t_img	ft_img(t_game *game, char c)
{
	if (c == 'N')
		return (game->n_img);
	if (c == 'S')
		return (game->s_img);
	if (c == 'E')
		return (game->e_img);
	if (c == 'W')
		return (game->w_img);
	return (game->color);
}

static void ft_color(t_game *game)
{
	int x;
	int y;

	x = -1;
	while (game->map.map[++x])
	{
		y = -1;
		while (game->map.map[x][++y])
		{
			if (game->map.map[x][y] == 'N' || game->map.map[x][y] == 'S'
				|| game->map.map[x][y] == 'E' || game->map.map[x][y] == 'W')
			{
				game->color = ft_img(game, game->map.map[x][y]);
				break;
			}
		}
	}
}

static int ft_rgb_color(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void fill_texture(t_img *texture, int color)
{
	int	x;
	int	y;

	y = -1;
	while (++y < texture->height)
	{
		x = -1;
		while (++x < texture->width)
			texture->data[y * (texture->size_line / 4) + x] = color;
	}
}

void load_textures(t_game *game, int ceiling, int floor)
{
	// Crear la textura del cielo
	game->ceiling.img = mlx_new_image(game->mlx, WIN_HEIGHT, WIN_WIDTH);
	game->ceiling.data = (int *)mlx_get_data_addr(game->ceiling.img,
		&game->ceiling.bpp, &game->ceiling.size_line, &game->ceiling.endian);
	game->ceiling.width = WIN_HEIGHT;
	game->ceiling.height = WIN_WIDTH;
	fill_texture(&game->ceiling, ceiling);

	// Crear la textura del suelo
	game->floor.img = mlx_new_image(game->mlx, WIN_HEIGHT, WIN_WIDTH / 1.25);
	game->floor.data = (int *)mlx_get_data_addr(game->floor.img, &game->floor.bpp,
		&game->floor.size_line, &game->floor.endian);
	game->floor.width = WIN_HEIGHT;
	game->floor.height = WIN_WIDTH / 1.25;
	fill_texture(&game->floor, floor);
}

static t_img start_xpm(t_game *game, char *str)
{
	game->img_data.img = mlx_xpm_file_to_image(game->mlx, str,
		&game->img_width, &game->img_height);
	if (game->img_data.img == NULL)
		ft_error("XPM to image fail!\n");
	game->img_data.data = (int *)mlx_get_data_addr(game->img_data.img,
		&game->bitpp, &game->line_len, &game->img_data.endian);
	return (game->img_data);
}

void all_xpm(t_game *game)
{
	game->n_img = start_xpm(game, game->map.nroute);
	game->s_img = start_xpm(game, game->map.sroute);
	game->e_img = start_xpm(game, game->map.eroute);
	game->w_img = start_xpm(game, game->map.wroute);
	game->f_color = ft_rgb_color(0, game->map.floor.r, game->map.floor.g, game->map.floor.b);
	game->c_color = ft_rgb_color(0, game->map.ceiling.r, game->map.ceiling.g, game->map.ceiling.b);
	load_textures(game, game->c_color, game->f_color);
	ft_color(game);
}

void print_img(t_game *game, void *img, int i, int j)
{
	mlx_put_image_to_window(game->mlx, game->win, img, i, j);
}

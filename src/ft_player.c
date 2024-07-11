/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:09:35 by rofuente          #+#    #+#             */
/*   Updated: 2024/07/11 15:38:41 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

static double ft_distance(double ray)
{
	return (fabs(1 / ray));
}

static void ft_walls(t_player *player)
{
	if (player->rayDirX < 0)
	{
		player->stepX = -1;
		player->sideDistX = (player->x - player->mapX) * player->deltaDistX;
	}
	else
	{
		player->stepX = 1;
		player->sideDistX = (player->mapX + 1.0 - player->x) * player->deltaDistX;
	}
	if (player->rayDirY < 0)
	{
		player->stepY = -1;
		player->sideDistY = (player->y - player->mapY) * player->deltaDistY;
	}
	else
	{
		player->stepY = 1;
		player->sideDistY = (player->mapY + 1.0 - player->y) * player->deltaDistY;
	}
}

static void ft_hit(t_player *player, t_game *game)
{
	while (player->hit == 0)
	{
		if (player->sideDistX < player->sideDistY)
		{
			player->sideDistX += player->deltaDistX;
			player->mapX += player->stepX;
			player->side = 0;
		}
		else
		{
			player->sideDistY += player->deltaDistY;
			player->mapY += player->stepY;
			player->side = 1;
		}
		if (game->map.map[player->mapX][player->mapY] == '1')
			player->hit = 1;
	}
	if (player->side == 0)
		player->perpWallDist = (player->mapX - player->x + (1 - player->stepX) / 2) / player->rayDirX;
	else
		player->perpWallDist = (player->mapY - player->y + (1 - player->stepY) / 2) / player->rayDirY;
}

static void ft_algorithm(t_player *player, t_game *game)
{
	player->mapX = (int)player->x;
	player->mapY = (int)player->y;
	player->deltaDistX = ft_distance(player->rayDirX);
	player->deltaDistY = ft_distance(player->rayDirY);
	ft_walls(player);
	ft_hit(player, game);
}

static void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0)
		return ;
	dst = data->addr + (y * data->size_line + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

static void ft_line(t_player *player, t_game *game, int x, int y, t_img *img)
{
	double	wallX;
	int		texX;
	int		texY;
	int		color;
	int		d;

	if (player->side == 0)
		wallX = player->y + player->perpWallDist * player->rayDirY;
	else
		wallX = player->x + player->perpWallDist * player->rayDirX;
	wallX -= floorf(wallX);
	texX = (int)(wallX * (double)game->color.width);
	if (player->side == 0 && player->rayDirX > 0)
		texX = game->color.width - texX - 1;
	if (player->side == 1 && player->rayDirY < 0)
		texX = game->color.width - texX - 1;
	y = player->drawStart - 1;
	while (++y < player->drawEnd)
	{
		d = y * 256 - WIN_HEIGHT * 128 + player->lineHeight * 128;
		texY = ((d * game->color.height) / player->lineHeight) / 256;
		color = game->color.addr[texY * game->color.size_line / 4 + texX];
		my_mlx_pixel_put(img, x, y, color);
	}
}

static void ft_print_fc(t_img *img, int color, int y)
{
	int x;

	while (++y < WIN_WIDTH)
	{
		x = -1;
		while (++x < WIN_HEIGHT)
			my_mlx_pixel_put(img, x, y, color);
	}
}

void render_scene(t_player *player, t_game *game, t_img *img)
{
	int x;

	ft_print_fc(img, game->c_color, -1);
	ft_print_fc(img, game->f_color, (WIN_WIDTH / 1.5) - 1);
	x = -1;
	while (++x < WIN_WIDTH)
	{
		player->cameraX = 2.0 * (x / (double)WIN_HEIGHT - 1);
		player->rayDirX = player->dirX + player->planeX * player->cameraX;
		player->rayDirY = player->dirY + player->planeY * player->cameraX;
		ft_algorithm(player, game);
		player->lineHeight = (int)(WIN_HEIGHT / player->perpWallDist);
		player->drawStart = (int)(-player->lineHeight / 2.0) + (WIN_HEIGHT / 2.0);
		if (player->drawStart < 0)
			player->drawStart = 0;
		player->drawEnd = (int)(player->lineHeight / 2.0) + (WIN_HEIGHT / 2.0);
		if (player->drawEnd >= WIN_HEIGHT)
			player->drawEnd = WIN_HEIGHT - 1;
		ft_line(player, game, x, 0, img);
	}
}

static void ft_dir(t_game *game, char c)
{
	if (c == 'N')
		ft_dir_n(game);
	if (c == 'S')
		ft_dir_s(game);
	if (c == 'E')
		ft_dir_e(game);
	if (c == 'W')
		ft_dir_w(game);
}

static void ft_pos(t_game *game)
{
	int x;
	int y;

	y = -1;
	while (game->map.map[++y])
	{
		x = -1;
		while (game->map.map[y][++x])
		{
			if (game->map.map[y][x] == 'N' || game->map.map[y][x] == 'S'
				|| game->map.map[y][x] == 'E' || game->map.map[y][x] == 'W')
			{
				game->player.x = x;
				game->player.y = y;
				ft_dir(game, game->map.map[y][x]);
				return ;
			}
		}
	}
}

int	ft_player(void *param)
{
	t_game	*game;
	t_img	img;

	game = (t_game *)param;
	img.img = mlx_new_image(game->mlx, WIN_HEIGHT, WIN_WIDTH);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.size_line, &img.endian);
	ft_pos(game);
	render_scene(&game->player, game, &img);
	// Imprime bien el suelo y cielo, pero ns xq no imprime las parades
	mlx_put_image_to_window(game->mlx, game->win, img.img, 0, 0);
	mlx_destroy_image(game->mlx, img.img);
	/* // Hay q ver si hay error al imprimir el mapa, si hay un error hay q devolver 1
	if (COMPROBCION ERROR)
		return (1); */
	return (0);
}

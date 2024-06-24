/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:09:35 by rofuente          #+#    #+#             */
/*   Updated: 2024/06/24 17:55:18 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void render_scene(void *mlx, void *win, t_player *player, t_game *game)
{
	int	x;
	int	y;

	x = -1;
	while (++x < WIN_WIDTH)
	{
		// Calcular la posición y dirección del rayo
		player->cameraX = 2 * x / (double)WIN_WIDTH - 1;
		player->rayDirX = player->dirX + player->planeX * player->cameraX;
		player->rayDirY = player->dirY + player->planeY * player->cameraX;
		// En que celda del mapa está el jugador
		player->mapX = (int)player->x;
		player->mapY = (int)player->y;
		// Distancia desde una celda a la próxima celda en x o y
		player->deltaDistX = fabs(1 / player->rayDirX);
		player->deltaDistY = fabs(1 / player->rayDirY);
		// Calcular step y sideDist inicial
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
		// Bucle DDA (Digital Differential Analyzer)
		while (player->hit == 0)
		{
			// Saltar al siguiente cuadrado del mapa
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
			// Comprobar si el rayo ha golpeado una pared
			if (game->map.map[player->mapX][player->mapY] == '1')
				player->hit = 1;
		}
		// Calcular la distancia perpendicular de la pared
		if (player->side == 0)
			player->perpWallDist = (player->mapX - player->x + (1 - player->stepX) / 2) / player->rayDirX;
		else
			player->perpWallDist = (player->mapY - player->y + (1 - player->stepY) / 2) / player->rayDirY;
		// Calcular la altura de la línea que se va a dibujar
		player->lineHeight = (int)(WIN_HEIGHT / player->perpWallDist);
		// Calcular las coordenadas de inicio y fin de la línea
		player->drawStart = -player->lineHeight / 2 + WIN_HEIGHT / 2;
		if (player->drawStart < 0)
			player->drawStart = 0;
		player->drawEnd = player->lineHeight / 2 + WIN_HEIGHT / 2;
		if (player->drawEnd >= WIN_HEIGHT)
			player->drawEnd = WIN_HEIGHT - 1;
		// Elegir el color de la pared (diferentes colores para diferentes lados)
		if (player->side == 1)
			player->color = game->f_color;
		else
			player->color = game->c_color;
		// Dibujar la línea vertical para la pared
		y = player->drawStart;
		while (y < player->drawEnd)
		{
			mlx_pixel_put(mlx, win, x, y, player->color);
			y++;
		}
	}
}

static void	ft_dir(t_game *game, char c)
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

static void	ft_pos(t_game *game)
{
	int	x;
	int	y;

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

void	ft_player(t_game *game)
{
	ft_pos(game);
	render_scene(game->mlx, game->win, &game->player, game);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 10:44:45 by rofuente          #+#    #+#             */
/*   Updated: 2024/09/09 14:00:44 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

static void	rotate(t_game *game, double speed)
{
	double	aux_dir;
	double	aux_plane;

	aux_dir = game->pc.dir.x;
	aux_plane = game->pc.plane.x;
	game->pc.dir.x = game->pc.dir.x * cos(speed) - game->pc.dir.y * sin(speed);
	game->pc.dir.y = aux_dir * sin(speed) + game->pc.dir.y * cos(speed);
	game->pc.plane.x = game->pc.plane.x * cos(speed)
		- game->pc.plane.y * sin(speed);
	game->pc.plane.y = aux_plane * sin(speed)
		+ game->pc.plane.y * cos(speed);
}

void	mouse_move(t_game *game)
{
	int	x;
	int	y;
	int	res;

	(void)res;
	x = 0;
	y = 0;
	mlx_mouse_hide(game->mlx, game->win);
	res = mlx_mouse_get_pos(game->mlx, game->win, &x, &y);
	if (x - game->mouse_pos.x > 50 || game->mouse_pos.x - x > 50)
	{
		if (x - game->mouse_pos.x > 50)
		{
			rotate(game, ROTATION);
			put_minimap(game);
		}
		else
		{
			rotate(game, -ROTATION);
			put_minimap(game);
		}
		res = mlx_mouse_move(game->mlx, game->win, 950, 600);
		game->mouse_pos.x = 950;
	}
}

static void	move(t_game *game, double x, double y, char sign)
{
	if (sign == '+')
	{
		if (game->dmap[(int)game->pc.pos.y][(int)(game->pc.pos.x + x)] != '1')
			game->pc.pos.x += x;
		if (game->dmap[(int)(game->pc.pos.y + y)][(int)game->pc.pos.x] != '1')
			game->pc.pos.y += y;
	}
	else if (sign == '-')
	{
		if (game->dmap[(int)game->pc.pos.y][(int)(game->pc.pos.x - x)] != '1')
			game->pc.pos.x -= x;
		if (game->dmap[(int)(game->pc.pos.y - y)][(int)game->pc.pos.x] != '1')
			game->pc.pos.y -= y;
	}
}

int	key_event(int key, t_game *game)
{
	if (key == KEY_ESC)
		close_window(game);
	else if (key == KEY_W)
		move(game, game->pc.dir.x * SPEED, game->pc.dir.y * SPEED, '+');
	else if (key == KEY_S)
		move(game, game->pc.dir.x * SPEED, game->pc.dir.y * SPEED, '-');
	else if (key == KEY_A)
		move(game, game->pc.plane.x * SPEED, game->pc.plane.y * SPEED, '-');
	else if (key == KEY_D)
		move(game, game->pc.plane.x * SPEED, game->pc.plane.y * SPEED, '+');
	else if ((key == ARROW_LEFT
			&& (game->pc.point == 'N' || game->pc.point == 'S'))
		|| (key == ARROW_RIGHT && (game->pc.point == 'E'
				|| game->pc.point == 'W')))
		rotate(game, -ROTATION);
	else if ((key == ARROW_LEFT
			&& (game->pc.point == 'E' || game->pc.point == 'W'))
		|| (key == ARROW_RIGHT && (game->pc.point == 'N'
				|| game->pc.point == 'S')))
		rotate(game, ROTATION);
	return (0);
}

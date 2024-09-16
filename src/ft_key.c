/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ken0by <ken0by@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 10:44:45 by rofuente          #+#    #+#             */
/*   Updated: 2024/09/12 12:01:33 by ken0by           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

static void	ft_rotate(t_game *game, double speed)
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

void	ft_mouse_move(t_game *game)
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
			ft_rotate(game, ROTATION);
			ft_minimap(game);
		}
		else
		{
			ft_rotate(game, -ROTATION);
			ft_minimap(game);
		}
		res = mlx_mouse_move(game->mlx, game->win, 950, 600);
		game->mouse_pos.x = 950;
	}
}

static void	ft_move(t_game *game, double x, double y, char sign)
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

int	ft_key(int key, t_game *game)
{
	if (key == KEY_ESC)
		ft_close(game);
	else if (key == KEY_W)
		ft_move(game, game->pc.dir.x * SPEED, game->pc.dir.y * SPEED, '+');
	else if (key == KEY_S)
		ft_move(game, game->pc.dir.x * SPEED, game->pc.dir.y * SPEED, '-');
	else if (key == KEY_A)
		ft_move(game, game->pc.plane.x * SPEED, game->pc.plane.y * SPEED, '-');
	else if (key == KEY_D)
		ft_move(game, game->pc.plane.x * SPEED, game->pc.plane.y * SPEED, '+');
	else if ((key == ARROW_LEFT
			&& (game->pc.point == 'N' || game->pc.point == 'S'))
		|| (key == ARROW_RIGHT && (game->pc.point == 'E'
				|| game->pc.point == 'W')))
		ft_rotate(game, -ROTATION);
	else if ((key == ARROW_LEFT
			&& (game->pc.point == 'E' || game->pc.point == 'W'))
		|| (key == ARROW_RIGHT && (game->pc.point == 'N'
				|| game->pc.point == 'S')))
		ft_rotate(game, ROTATION);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ken0by <ken0by@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 20:09:22 by ken0by            #+#    #+#             */
/*   Updated: 2024/06/26 20:21:53 by ken0by           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

static void	press_r(t_game *game)
{
	int	x;
	int	y;

	x = -1;
	while (game->map.map[++x])
	{
		y = -1;
		while (game->map.map[x][++y])
		{
			if (game->map.map[x][y] == 'N' || game->map.map[x][y] == 'S'
				|| game->map.map[x][y] == 'E' || game->map.map[x][y] == 'W')
			{
				game->map.map[x][y] = 'W';
				return ;
			}
		}
	}
}

static void	press_l(t_game *game)
{
	int	x;
	int	y;

	x = -1;
	while (game->map.map[++x])
	{
		y = -1;
		while (game->map.map[x][++y])
		{
			if (game->map.map[x][y] == 'N' || game->map.map[x][y] == 'S'
				|| game->map.map[x][y] == 'E' || game->map.map[x][y] == 'W')
			{
				game->map.map[x][y] = 'E';
				return ;
			}
		}
	}
}

static void	press_w(t_game *game)
{
	int	x;
	int	y;

	x = -1;
	while (game->map.map[++x])
	{
		y = -1;
		while (game->map.map[x][++y])
		{
			if ((game->map.map[x][y] == 'N' || game->map.map[x][y] == 'S'
				|| game->map.map[x][y] == 'E' || game->map.map[x][y] == 'W') && (game->map.map[x - 1][y] != '1'))
			{
				game->map.map[x][y] = '0';
				game->map.map[x - 1][y] = 'N';
				return ;
			}
		}
	}
}

static void	press_s(t_game *game)
{
	int	x;
	int	y;

	x = -1;
	while (game->map.map[++x])
	{
		y = -1;
		while (game->map.map[x][++y])
		{
			if ((game->map.map[x][y] == 'N' || game->map.map[x][y] == 'S'
				|| game->map.map[x][y] == 'E' || game->map.map[x][y] == 'W') && (game->map.map[x + 1][y] != '1'))
			{
				game->map.map[x][y] = '0';
				game->map.map[x + 1][y] = 'S';
				return ;
			}
		}
	}
}

static void	press_d(t_game *game)
{
	int	x;
	int	y;

	x = -1;
	while (game->map.map[++x])
	{
		y = -1;
		while (game->map.map[x][++y])
		{
			if ((game->map.map[x][y] == 'N' || game->map.map[x][y] == 'S'
				|| game->map.map[x][y] == 'E' || game->map.map[x][y] == 'W') && (game->map.map[x][y + 1] != '1'))
			{
				game->map.map[x][y] = '0';
				game->map.map[x][y + 1] = 'W';
				return ;
			}
		}
	}
}

static void	press_a(t_game *game)
{
	int	x;
	int	y;

	x = -1;
	while (game->map.map[++x])
	{
		y = -1;
		while (game->map.map[x][++y])
		{
			if ((game->map.map[x][y] == 'N' || game->map.map[x][y] == 'S'
				|| game->map.map[x][y] == 'E' || game->map.map[x][y] == 'W') && (game->map.map[x][y - 1] != '1'))
			{
				game->map.map[x][y] = '0';
				game->map.map[x][y - 1] = 'W';
				return ;
			}
		}
	}
}

int	ft_key(int key, t_game *game)
{
	if (key == KEY_ESC)
	{
		//ft_close(game);
		exit(EXIT_SUCCESS);
	}
	if (key == ARROW_RIGHT)
		press_r(game);
	if (key == ARROW_LEFT)
		press_l(game);
	if (key == KEY_W)
		press_w(game);
	if (key == KEY_S)
		press_s(game);
	if (key == KEY_D)
		press_d(game);
	if (key == KEY_A)
		press_a(game);
	return (0);
}

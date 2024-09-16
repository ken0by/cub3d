/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ken0by <ken0by@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 10:54:27 by rofuente          #+#    #+#             */
/*   Updated: 2024/09/16 11:31:04 by ken0by           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

static int	ft_around(char **map, int i, int j)
{
	if (i == 0)
		return (0);
	if (i > 0 && map[i - 1][j] != '1' && map[i - 1][j] != 'x')
		return (0);
	if (map[i][j + 1] != '\0' && map[i][j + 1] != '1' && map[i][j + 1] != 'x')
		return (0);
	if (map[i + 1] != NULL && map[i + 1][j] != '1' && map[i + 1][j] != 'x')
		return (0);
	if (j > 0 && map[i][j - 1] != '1' && map[i][j - 1] != 'x')
		return (0);
	if (!map[i + 1])
		return (0);
	return (1);
}

static int	ft_walls(char **map)
{
	int	i;
	int	j;
	int	ret;

	i = 0;
	ret = 1;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'x')
				ret = ft_around(map, i, j);
			if (!ret)
				return (ret);
			j++;
		}
		i++;
	}
	return (ret);
}

static int	ft_play(char **map)
{
	int	player;
	int	i;
	int	j;

	i = 0;
	j = 0;
	player = 0;
	while (map[i] != NULL)
	{
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'N' || map[i][j] == 'E'
				|| map[i][j] == 'S' || map[i][j] == 'W')
			{
				map[i][j] = '0';
				player++;
			}
			j++;
		}
		i++;
		j = 0;
	}
	return (player);
}

static int	ft_content(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i] != NULL)
	{
		while (map[i][j] != '\0')
		{
			if (map[i][j] != 'N' && map[i][j] != 'E' && map[i][j] != 'S' &&
				map[i][j] != 'W' && map[i][j] != '0' && map[i][j] != '1' &&
				map[i][j] != '\n' && map[i][j] != ' ')
				return (0);
			j++;
		}
		i++;
		j = 0;
	}
	return (1);
}

int	ft_map_check(t_game *game)
{
	if (!ft_content(game->map))
		return (0);
	if (ft_play(game->map) != 1)
		return (0);
	if (!ft_walls(game->dmap))
		return (0);
	return (1);
}

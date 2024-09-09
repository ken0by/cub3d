/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 10:54:27 by rofuente          #+#    #+#             */
/*   Updated: 2024/09/09 10:55:01 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

static int	check_adjacent(char **map, int i, int j)
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

static int	check_walls(char **map)
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
				ret = check_adjacent(map, i, j);
			if (!ret)
				return (ret);
			j++;
		}
		i++;
	}
	return (ret);
}

static int	check_player(char **map)
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

static int	check_chars(char **map)
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

int	map_validity(t_game *game)
{
	if (!check_chars(game->map))
		return (0);
	if (check_player(game->map) != 1)
		return (0);
	if (!check_walls(game->dmap))
		return (0);
	return (1);
}

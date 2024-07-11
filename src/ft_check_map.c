/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 14:09:11 by rofuente          #+#    #+#             */
/*   Updated: 2024/07/11 11:36:35 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

static void	ft_compare(int n, int s, int e, int w)
{
	if ((n < 0 && n > 1)|| (s < 0 && s > 1) || (e < 0 && e > 1) || (w < 0 && w > 1))
		ft_error("Invalid elements\n");
	if (n == 1 && (s == 1 || e == 1 || w ==1))
		ft_error("Invalid elements\n");
	if (s == 1 && (n == 1 || e == 1 || w ==1))
		ft_error("Invalid elements\n");
	if (e == 1 && (s == 1 || n == 1 || w ==1))
		ft_error("Invalid elements\n");
	if (w == 1 && (s == 1 || e == 1 || n ==1))
		ft_error("Invalid elements\n");
}

static void	ft_check_elements(char **map, int n, int s, int e)
{
	int	i;
	int	j;
	int w;

	w = 0;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'N')
				n++;
			if (map[i][j] == 'S')
				s++;
			if (map[i][j] == 'E')
				e++;
			if (map[i][j] == 'W')
				w++;
		}
	}
	ft_compare(n, s, e, w);
}

static void	ft_check_diferent(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] != ' ' && map[i][j] != '0' && map[i][j] != '1'
				&& map[i][j] != 'N' && map[i][j] != 'S'
				&& map[i][j] != 'E' && map[i][j] != 'W' && map[i][j] != '\n')
			{
				printf("ERROR-> \"%c\"\n", map[i][j]);
				ft_error("Found unrecognized element\n");
			}
		}
	}
}

static void	ft_check_walls(char **map)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (map[0][i] == ' ')
		i++;
	while (map[0][i])
	{
		if (map[0][i] == '\n' || map[0][i] == '\0')
			break;
		if (map[0][i] == ' ')
		{
			k = 1;
			while (map[0 + k][i] != '1')
			{
				if (map[0 + k][i - 1] != '1' || map[0 + k][i + 1] != '1')
					ft_error("Map isn't surrounded of walls\n");
				k++;
			}
			if (map[0 + k][i - 1] != '1' || map[0 + k][i + 1] != '1')
				ft_error("Map isn't surrounded of walls\n");
		} else if (map[0][i] != '1')
			ft_error("Map isn't surrounded of walls\n");
		i++;
	}
	j = 0;
	while (map[++j])
	{
		if (map[j][0] == ' ')
		{
			k = 0;
			while (map[j][k] == ' ')
				k++;
			if (map[j][k] != '1')
				ft_error("Map isn't surrounded of walls\n");
		} else if (map[j][0] != '1')
			ft_error("Map isn't surrounded of walls\n");
		if (map[j][ft_strlen(map[j]) - 2] != '1' && map[j][ft_strlen(map[j]) - 2] != ' ')
			ft_error("Map isn't surrounded of walls\n");
	}
	i = -1;
	j--;
	while (map[j][++i])
	{
		if (map[j][i] == '\n' || map[j][i] == '\0')
			break ;
		if (map[j][i] == ' ')
		{
			k = 1;
			while (map[j - k][i] != '1')
			{
				if (map[j - k][i - 1] != '1' || map[j - k][i + 1] != '1')
					ft_error("Map isn't surrounded of walls\n");
				k++;
			}
			if (map[j - k][i - 1] != '1' || map[j - k][i + 1] != '1')
				ft_error("Map isn't surrounded of walls\n");
		}
		else if (map[j][i] != '1')
			ft_error("Map isn't surrounded of walls\n");
	}
}

void	ft_check_map(t_game *game)
{
	ft_check_elements(game->map.map, 0, 0, 0);
	ft_check_diferent(game->map.map);
	ft_check_walls(game->map.map);
}

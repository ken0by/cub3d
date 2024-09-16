/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ken0by <ken0by@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 10:50:07 by rofuente          #+#    #+#             */
/*   Updated: 2024/09/16 11:19:35 by ken0by           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	ft_destroy(t_game *game)
{
	int	i;

	i = 0;
	if (game->mlx)
	{
		while (i < 5)
		{
			if (game->img[i].img)
				mlx_destroy_image(game->mlx, game->img[i].img);
			i++;
		}
	}
}

int	ft_close(t_game *game)
{
	ft_clean_game(game);
	ft_destroy(game);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	exit(0);
}

int	ft_nb_to_hex(char **number)
{
	int	hex;
	int	r;
	int	g;
	int	b;

	r = ft_atoi(number[0]);
	g = ft_atoi(number[1]);
	b = ft_atoi(number[2]);
	hex = r;
	hex = (hex << 8) + g;
	hex = (hex << 8) + b;
	return (hex);
}

void	ft_dmap(t_game *game)
{
	int	i;

	i = 0;
	game->dmap = ft_calloc(game->map_height + 1, sizeof(char *));
	if (!game->dmap)
		return ;
	while (i < game->map_height)
	{
		game->dmap[i] = ft_strdup(game->map[i]);
		i++;
	}
}

void	ft_floodfill(char **map_dup, int x, int y)
{
	map_dup[y][x] = 'x';
	if (y > 0 && map_dup[y - 1][x] == '0' && map_dup[y - 1][x] != 'x')
		ft_floodfill(map_dup, x, y - 1);
	if (map_dup[y][x + 1] != '\0'
		&& map_dup[y][x + 1] == '0' && map_dup[y][x + 1] != 'x')
		ft_floodfill(map_dup, x + 1, y);
	if (map_dup[y + 1] != NULL
		&& map_dup[y + 1][x] == '0' && map_dup[y + 1][x] != 'x')
		ft_floodfill(map_dup, x, y + 1);
	if (x > 0 && map_dup[y][x - 1] == '0' && map_dup[y][x - 1] != 'x')
		ft_floodfill(map_dup, x - 1, y);
}

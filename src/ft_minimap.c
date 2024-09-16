/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ken0by <ken0by@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 13:43:26 by rofuente          #+#    #+#             */
/*   Updated: 2024/09/16 11:33:39 by ken0by           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"


static void	ft_paint(t_game *game, int map_width)
{
	t_vec	vect;
	t_map	map_args;

	map_args.scale = game->map_height * 10 / map_width;
	map_args.color = 0x0000FF;
	vect.x = game->pc.pos.x;
	vect.y = game->pc.pos.y;
	ft_line(game, vect, map_args);
	map_args.color = 0xFF0000;
	ft_circle(game, vect, 5, map_args);
}

static void	ft_scale(t_game *game, float scale)
{
	int		y;
	int		x;
	t_map	map;
	t_map	map2;

	map.scale = scale;
	map2.scale = scale;
	map.color = ft_trgb(0, 132, 128, 128);
	map2.color = ft_trgb(0, 53, 48, 48);
	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] != '0' && game->map[y][x] != '1')
				ft_scaled_pixel(game, x, y, map);
			if (game->map[y][x] == '0')
				ft_scaled_pixel(game, x, y, map);
			else if (game->map[y][x] == '1')
				ft_scaled_pixel(game, x, y, map2);
			x++;
		}
		y++;
	}
}

void	ft_pixel2(t_game *game, int x, int y, int color)
{
	char	*pixel;

	if (y < 0 || y > (game->map_height * 10) || x < 0
		|| x > (game->map_width * 10))
		return ;
	pixel = (game->img[4].ptr + (y * game->img[4].size_line
				+ x * (game->img[4].bpp / 8)));
	*(int *)pixel = color;
}

int	ft_minimap(t_game *game)
{
	float	scale;

	scale = game->map_height * 10 / game->map_width;
	ft_scale(game, scale);
	ft_paint(game, game->map_width);
	return (1);
}

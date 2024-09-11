/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ken0by <ken0by@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 11:17:24 by ken0by            #+#    #+#             */
/*   Updated: 2024/09/11 11:51:41 by ken0by           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

static void	draw_circle_util(t_game *game, t_vec cntr, t_vec pos, t_map map)
{
	put_pixel2(game, cntr.x + pos.x, cntr.y + pos.y, map.color);
	put_pixel2(game, cntr.x + pos.y, cntr.y + pos.x, map.color);
	put_pixel2(game, cntr.x - pos.y, cntr.y + pos.x, map.color);
	put_pixel2(game, cntr.x - pos.x, cntr.y + pos.y, map.color);
	put_pixel2(game, cntr.x - pos.x, cntr.y - pos.y, map.color);
	put_pixel2(game, cntr.x - pos.y, cntr.y - pos.x, map.color);
	put_pixel2(game, cntr.x + pos.y, cntr.y - pos.x, map.color);
	put_pixel2(game, cntr.x + pos.x, cntr.y - pos.y, map.color);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	draw_line(t_game *game, t_vec vect, t_map map)
{
	float	dx;
	float	to_x;
	float	to_y;

	dx = 0;
	norm_vect(game->pc.dir);
	to_x = game->pc.dir.x;
	to_y = game->pc.dir.y;
	while (dx < 10 && dx >= 0)
	{
		put_pixel2(game, (vect.x * map.scale) + (dx * to_x),
			(vect.y * map.scale) + (dx * to_y), map.color);
		dx += 0.25;
	}
}

void	draw_circle(t_game *game, t_vec vect, int radius, t_map map)
{
	t_vec	cntr;
	t_vec	pos;
	float	radius_error;

	cntr.x = vect.x * map.scale;
	cntr.y = vect.y * map.scale;
	pos.x = radius;
	pos.y = 0;
	radius_error = 1 - pos.x;
	while (pos.x >= pos.y)
	{
		draw_circle_util(game, cntr, pos, map);
		pos.y++;
		if (radius_error < 0)
		{
			radius_error += 2 * pos.y + 1;
		}
		else
		{
			pos.x--;
			radius_error += 2 * (pos.y - pos.x + 1);
		}
	}
}

void	draw_scaled_pixel(t_game *game, int x, int y, t_map map)
{
	int	dy;
	int	dx;

	dy = -1;
	while (++dy < map.scale)
	{
		dx = -1;
		while (++dx < map.scale)
		{
			put_pixel2(game, x * map.scale + dx,
				y * map.scale + dy, map.color);
		}
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ken0by <ken0by@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 13:43:26 by rofuente          #+#    #+#             */
/*   Updated: 2024/09/10 11:54:51 by ken0by           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	put_pixel2(t_game *game, int x, int y, int color)
{
	char	*pixel;

	if (y < 0 || y > (game->map_height * 10) || x < 0
		|| x > (game->map_width * 10))
		return ;
	pixel = (game->m_map.ptr + (y * game->m_map.size_line
				+ x * (game->m_map.bpp / 8)));
	*(int *)pixel = color;
}

float dot_prod(t_vec v1, t_vec v2) {
    return v1.x * v2.x + v1.y * v2.y;
}


t_vec	sub_v(t_vec v1, t_vec v2)
{
	t_vec	res;

	res.y = v1.y - v2.y;
	res.x = v1.x - v2.x;
	return (res);
}

float	dist_vec(t_vec v1, t_vec v2)
{
	float	res;
	t_vec	temp;

	temp = sub_v(v2, v1);
	res = sqrtf(dot_prod(temp, temp));
	return (res);
}

float	size_vect(t_vec v)
{
	t_vec	zero;

	zero.x = 0;
	zero.y = 0;
	return (dist_vec(v, zero));
}

t_vec	f_x_v(float f, t_vec v)
{
	t_vec	res;

	res.x = v.x * f;
	res.y = v.y * f;
	return (res);
}

t_vec	norm_vect(t_vec v1)
{
	return (f_x_v(1 / size_vect(v1), v1));
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

void	draw_circle_util(t_game *game, t_vec cntr, t_vec pos, t_map map)
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

void	draw_player(t_game *game, int map_width)
{
	t_vec	vect;
	t_map	map_args;

	map_args.scale = game->map_height * 10 / map_width;
	map_args.color = 0x0000FF;
	vect.x = game->pc.pos.x;
	vect.y = game->pc.pos.y;
	draw_line(game, vect, map_args);
	map_args.color = 0xFF0000;
	draw_circle(game, vect, 5, map_args);
}

void	scale_map2(t_game *game, float scale)
{
	int		y;
	int		x;
	t_map	map;
	t_map	map2;

	map.scale = scale;
	map2.scale = scale;
	map.color = create_trgb(0, 132, 128, 128);
	map2.color = create_trgb(0, 53, 48, 48);
	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] != '0' && game->map[y][x] != '1')
				draw_scaled_pixel(game, x, y, map);
			if (game->map[y][x] == '0')
				draw_scaled_pixel(game, x, y, map);
			else if (game->map[y][x] == '1')
				draw_scaled_pixel(game, x, y, map2);
			x++;
		}
		y++;
	}
}

void	scale_map(t_game *game, int map_width)
{
	float	scale;

	scale = game->map_height * 10 / map_width;
	scale_map2(game, scale);
	draw_player(game, map_width);
}

int	put_minimap(t_game *game)
{
	game->m_map.img = mlx_new_image(game->mlx, game->map_width * 10,
			game->map_height * 10);
	game->m_map.ptr = mlx_get_data_addr(game->m_map.img, &game->m_map.bpp,
			&game->m_map.size_line, &game->m_map.endian);
	scale_map(game, game->map_width);
	mlx_put_image_to_window(game->mlx, game->win, game->m_map.img, 0, 0);
	return (1);
}

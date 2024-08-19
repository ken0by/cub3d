/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 11:14:46 by rofuente          #+#    #+#             */
/*   Updated: 2024/08/19 12:39:20 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

t_vec	sub_v(t_vec v1, t_vec v2)
{
	t_vec	res;

	res.y = v1.y - v2.y;
	res.x = v1.x - v2.x;
	return (res);
}

float	dot_prod(t_vec v1, t_vec v2)
{
	return (v1.x * v2.x + v1.y * v2.y);
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

t_vec	norm_vect(t_vec v1)
{
	return (ft_fxv(v1, 1 / size_vect(v1)));
}

void	draw_line(t_game *vars, t_img *m_map, t_vec vect, t_map map)
{
	float	dx;
	float	to_x;
	float	to_y;

	dx = 0;
	norm_vect(vars->player.face);
	to_x = vars->player.face.x;
	to_y = vars->player.face.y;
	while (dx < 10 && dx >= 0)
	{
		my_mlx_pixel_put(m_map, (vect.x * map.scale) + (dx * to_x),
			(vect.y * map.scale) + (dx * to_y), map.color);
		dx += 0.25;
	}
}

void	draw_circle_util(t_img *m_map, t_vec cntr, t_vec pos, t_map map)
{
	my_mlx_pixel_put(m_map, cntr.x + pos.x, cntr.y + pos.y, map.color);
	my_mlx_pixel_put(m_map, cntr.x + pos.y, cntr.y + pos.x, map.color);
	my_mlx_pixel_put(m_map, cntr.x - pos.y, cntr.y + pos.x, map.color);
	my_mlx_pixel_put(m_map, cntr.x - pos.x, cntr.y + pos.y, map.color);
	my_mlx_pixel_put(m_map, cntr.x - pos.x, cntr.y - pos.y, map.color);
	my_mlx_pixel_put(m_map, cntr.x - pos.y, cntr.y - pos.x, map.color);
	my_mlx_pixel_put(m_map, cntr.x + pos.y, cntr.y - pos.x, map.color);
	my_mlx_pixel_put(m_map, cntr.x + pos.x, cntr.y - pos.y, map.color);
}

void	draw_circle(t_img *m_map, t_vec vect, int radius, t_map map)
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
		draw_circle_util(m_map, cntr, pos, map);
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

void	draw_scaled_pixel(t_img *m_map, int x, int y, t_map map)
{
	int	dy;
	int	dx;

	dy = 0;
	while (dy < map.scale)
	{
		dx = 0;
		while (dx < map.scale)
		{
			my_mlx_pixel_put(m_map, x * map.scale + dx,
				y * map.scale + dy, map.color);
			dx++;
		}
		dy++;
	}
}

void	draw_player(t_game *vars, t_img *m_map, int map_width)
{
	t_vec	vect;
	t_map	map_args;

	map_args.scale = vars->map.height * 10 / map_width;
	map_args.color = 0x0000FF;
	vect.x = vars->pos.x;
	vect.y = vars->pos.y;
	draw_line(vars, m_map, vect, map_args);
	map_args.color = 0xFF0000;
	draw_circle(m_map, vect, 5, map_args);
}

void	scale_map2(t_game *vars, t_img *m_map, float scale)
{
	int		y;
	int		x;
	t_map	map;
	t_map	map2;

	map.scale = scale;
	map2.scale = scale;
	map.color = ft_rgb_color(0, 132, 128, 128);
	map2.color = ft_rgb_color(0, 53, 48, 48);
	y = -1;
	while (++y < vars->map.width)
	{
		x = -1;
		while (++x < vars->map.height)
		{
			if (vars->map.map[y][x] != '0' && vars->map.map[y][x] != '1')
				draw_scaled_pixel(m_map, x, y, map);
			if (vars->map.map[y][x] == '0')
				draw_scaled_pixel(m_map, x, y, map);
			else if (vars->map.map[y][x] == '1')
				draw_scaled_pixel(m_map, x, y, map2);
		}
	}
}

void	scale_map(t_game *vars, t_img *m_map, int map_width)
{
	float	scale;

	scale = vars->map.height * 10 / map_width;
	scale_map2(vars, m_map, scale);
	draw_player(vars, m_map, map_width);
}

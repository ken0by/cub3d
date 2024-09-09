/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 10:42:41 by rofuente          #+#    #+#             */
/*   Updated: 2024/09/09 14:01:58 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	put_pixel(t_game *game, int x, int y, int color)
{
	char	*pixel;

	if (y < 0 || y > HEIGHT - 1 || x < 0
		|| x > WIDTH - 1)
		return ;
	pixel = (game->img[4].ptr + (y * game->img[4].size_line
				+ x * (game->img[4].bpp / 8)));
	*(int *)pixel = color;
}

void	render_background(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			if (y < HEIGHT / 2)
				put_pixel(game, x, y, number_to_hex(game->tex.c));
			else
				put_pixel(game, x, y, number_to_hex(game->tex.f));
			y++;
		}
		++x;
	}
}

int	render(t_game *game)
{
	mouse_move(game);
	render_background(game);
	raycasting(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img[4].img, 0, 0);
	if (!put_minimap(game))
		return (1);
	return (0);
}

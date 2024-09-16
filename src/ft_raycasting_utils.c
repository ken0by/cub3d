/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ken0by <ken0by@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 10:58:09 by rofuente          #+#    #+#             */
/*   Updated: 2024/09/12 12:02:32 by ken0by           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

static int	ft_get_color(t_game *game, int x, int y, int texture)
{
	return (*(int *)(game->img[texture].ptr
		+ (y * game->img[texture].size_line
			+ x * (game->img[texture].bpp / 8))));
}

static void	ft_draw_pixel(t_game *game, int x, int texture)
{
	int	color;

	color = ft_get_color(game, game->ray.tex.x, game->ray.tex.y, texture);
	ft_pixel(game, x, game->ray.line_start, color);
}

static void	ft_map_texture(t_game *game, int start, int line_height)
{
	if (game->ray.side == 0)
		game->ray.wall_x = game->pc.pos.y + game->ray.perpwalldist
			* game->ray.dir.y;
	else
		game->ray.wall_x = game->pc.pos.x + game->ray.perpwalldist
			* game->ray.dir.x;
	game->ray.wall_x -= floor(game->ray.wall_x);
	game->ray.tex.x = game->ray.wall_x * TEXTURE_WIDTH;
	if (game->ray.side == 0 && game->ray.dir.x > 0)
		game->ray.tex.x = TEXTURE_WIDTH - game->ray.tex.x - 1;
	if (game->ray.side == 1 && game->ray.dir.y < 0)
		game->ray.tex.x = TEXTURE_WIDTH - game->ray.tex.x - 1;
	game->ray.tex_step = 1.0 * TEXTURE_HEIGHT / line_height;
	game->ray.tex_pos = (start - HEIGHT / 2
			+ line_height / 2) * game->ray.tex_step;
}

static void	ft_line2(t_game *game, int *line_height, int *start, int *end)
{
	*line_height = HEIGHT / game->ray.perpwalldist;
	*start = -*line_height / 2 + HEIGHT / 2;
	if (*start < 0)
		*start = 0;
	*end = *line_height / 2 + HEIGHT / 2;
	if (*end >= HEIGHT)
		*end = HEIGHT - 1;
}

void	ft_draw(t_game *game, int x)
{
	int	line_height;

	ft_line2(game, &line_height, &game->ray.line_start, &game->ray.line_end);
	ft_map_texture(game, game->ray.line_start, line_height);
	while (game->ray.line_start < game->ray.line_end)
	{
		game->ray.tex.y = (int)game->ray.tex_pos & (TEXTURE_HEIGHT - 1);
		game->ray.tex_pos += game->ray.tex_step;
		if (game->ray.side == 1 && game->ray.dir.y < 0)
			ft_draw_pixel(game, x, 1);
		else if (game->ray.side == 1 && game->ray.dir.y > 0)
			ft_draw_pixel(game, x, 0);
		else if (game->ray.side == 0 && game->ray.dir.x < 0)
			ft_draw_pixel(game, x, 3);
		else if (game->ray.side == 0 && game->ray.dir.x > 0)
			ft_draw_pixel(game, x, 2);
		game->ray.line_start++;
	}
	(void)game;
	(void)x;
}

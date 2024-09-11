/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ken0by <ken0by@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 10:33:43 by rofuente          #+#    #+#             */
/*   Updated: 2024/09/11 10:59:59 by ken0by           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	init_img(t_game *game)
{
	int	i;

	i = 0;
	game->img[0].img = mlx_xpm_file_to_image(game->mlx, game->tex.n,
			&game->img[0].w, &game->img[0].h);
	game->img[1].img = mlx_xpm_file_to_image(game->mlx, game->tex.s,
			&game->img[1].w, &game->img[1].h);
	game->img[2].img = mlx_xpm_file_to_image(game->mlx, game->tex.e,
			&game->img[2].w, &game->img[2].h);
	game->img[3].img = mlx_xpm_file_to_image(game->mlx, game->tex.w,
			&game->img[3].w, &game->img[3].h);
	game->img[4].img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	while (i < 5)
	{
		game->img[i].ptr = mlx_get_data_addr(game->img[i].img,
				&game->img[i].bpp, &game->img[i].size_line,
				&game->img[i].endian);
		i++;
	}
}

void	init_cameraplane(t_game *game)
{
	if (game->pc.point == 'N')
	{
		game->pc.plane.x = 0.66;
		game->pc.plane.y = 0;
	}
	if (game->pc.point == 'S')
	{
		game->pc.plane.x = -0.66;
		game->pc.plane.y = 0;
	}
	if (game->pc.point == 'W')
	{
		game->pc.plane.x = 0;
		game->pc.plane.y = 0.66;
	}
	if (game->pc.point == 'E')
	{
		game->pc.plane.x = 0;
		game->pc.plane.y = -0.66;
	}
}

static void	init_vecs(t_game *game, int i, int j)
{
	if (game->map[i][j] == 'N')
	{
		game->pc.pos = (t_vec){j, i};
		game->pc.dir = (t_vec){0, -1};
		game->pc.point = 'N';
	}
	else if (game->map[i][j] == 'S')
	{
		game->pc.pos = (t_vec){j, i};
		game->pc.dir = (t_vec){0, 1};
		game->pc.point = 'S';
	}
	else if (game->map[i][j] == 'E')
	{
		game->pc.pos = (t_vec){j, i};
		game->pc.dir = (t_vec){1, 0};
		game->pc.point = 'E';
	}
	else if (game->map[i][j] == 'W')
	{
		game->pc.pos = (t_vec){j, i};
		game->pc.dir = (t_vec){-1, 0};
		game->pc.point = 'W';
	}
}

void	init_player(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	game->pc.fov = 0;
	game->pc.dir.x = 0;
	game->pc.dir.y = 0;
	game->pc.pos.x = 0;
	game->pc.pos.y = 0;
	while (game->map[i] != NULL)
	{
		while (game->map[i][j] != '\0')
		{
			init_vecs(game, i, j);
			j++;
		}
		i++;
		j = 0;
	}
}

void	init_data(t_game *game)
{
	int	i;

	i = 0;
	game->map_height = 0;
	game->map_width = 0;
	game->map_data.lines = 0;
	game->map = NULL;
	game->dmap = NULL;
	game->tex.n = NULL;
	game->tex.s = NULL;
	game->tex.e = NULL;
	game->tex.w = NULL;
	game->tex.f = NULL;
	game->tex.c = NULL;
	while (i < 5)
	{
		game->img[i].img = NULL;
		game->img[i].ptr = NULL;
		i++;
	}
	game->mouse_pos.x = 0;
	game->mouse_pos.y = 0;
	game->scale = 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ken0by <ken0by@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 10:13:29 by rofuente          #+#    #+#             */
/*   Updated: 2024/09/16 11:27:26 by ken0by           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	ft_clean_game(t_game *game)
{
	if (game->map_data.map_cpy)
		ft_free_arr(game->map_data.map_cpy);
	if (game->map)
		ft_free_arr(game->map);
	if (game->dmap)
		ft_free_arr(game->dmap);
	ft_free_inf(game);
}

void	ft_error(t_game *game, char *error)
{
	ft_printf(error);
	ft_clean_game(game);
	exit(1);
}

static int	ft_game(t_game *game)
{
	ft_camerap(game);
	game->mlx = mlx_init();
	if (!game->mlx)
		return (0);
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "Cube3D");
	if (game->win == NULL)
		return (0);
	ft_img(game);
	mlx_hook(game->win, 2, 1L << 0, ft_key, game);
	mlx_loop_hook(game->mlx, &ft_render, game);
	mlx_hook(game->win, 17, 1L << 17, ft_close, game);
	mlx_loop(game->mlx);
	return (1);
}

static void	ft_check(t_game *game)
{
	ft_dmap(game);
	ft_floodfill(game->dmap, game->pc.pos.x, game->pc.pos.y);
	if (!ft_map_check(game))
		ft_error(game, "Error in map validation\n");
	else if (!ft_check_inf(game->tex))
		ft_error(game, "Error in textures validation\n");
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_printf("Error: one argument expected\n");
		return (1);
	}
	ft_data(&game);
	if (!ft_parse(&game, argv))
		ft_error(&game, "Error during parsing\n");
	ft_player(&game);
	ft_check(&game);
	if (!ft_game(&game))
		ft_error(&game, "Error initializing game\n");
	return (0);
}

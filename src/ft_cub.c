/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ken0by <ken0by@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 13:07:31 by rofuente          #+#    #+#             */
/*   Updated: 2024/06/26 21:10:36 by ken0by           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	ft_error(char *s)
{
	ft_putstr_fd(RED "Error: " RESET, 2);
	ft_putstr_fd(RED, 2);
	ft_putstr_fd(s, 2);
	ft_putstr_fd(RESET, 2);
	exit (EXIT_FAILURE);
}

static void	ft_check_extension(char *file, char *ext)
{
	int	i;
	int	j;

	i = ft_strlen(file) - ft_strlen(ext);
	j = 0;
	while (file[i + j] && ext[j])
	{
		if (file[i + j] == ext[j])
			j++;
		else
		{
			ft_printf("Map file extetion is not '.cub'\n");
			exit(1);
		}
	}
}

static void	ft_check_pname(char *pro, char *name)
{
	int	i;

	i = 0;
	while (pro[i] && name[i])
	{
		if (pro[i] == name[i])
			i++;
		else
		{
			ft_printf("Program name is not './cub3D'\n");
			exit(1);
		}
	}
}

static void	ft_strat(t_game *game, char *map)
{
	ft_read_map(game, map);
	game->mlx = mlx_init();
	if (!game->mlx)
		ft_error("Failed to open MLX\n");
	game->win = mlx_new_window(game->mlx, WIN_HEIGHT, WIN_WIDTH, "Cub3D");
	if (!game->win)
		ft_error("Failed to load window\n");
	game->img = mlx_new_image(game->mlx,WIN_HEIGHT, WIN_HEIGHT);
	if (!game->img)
		ft_error("Failed to launch image\n");
	game->ads = (int *)mlx_get_data_addr(game->mlx, &game->bitpp, &game->line_len, &game->endian);
	if (!game->ads)
		ft_error("Failed to load addres image\n");
	all_xpm(game);
	ft_player(game);
}

static void	ft_cub(char **argv)
{
	ft_check_pname(argv[0], "./cub3D");
	ft_check_extension(argv[1], ".cub");
}

static int	red_cross(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit (0);
}

int	main(int argc, char **argv)
{
	t_game game;

	if (argc == 2)
	{
		ft_cub(argv);
		ft_strat(&game, argv[1]);
		mlx_hook(game.win, DESTROY, 0, red_cross, &game);
		mlx_hook(game.win, 17, (1L << 0), &red_cross, &game);
		mlx_hook(game.win, 2, (1L << 0), &ft_key, &game);
		// mlx_loop_hook(game.mlx, &ft_loop, &game);
		mlx_loop(game.mlx);
	}
	else
		ft_error("Please run: ./cub3D [map].cub");
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 13:07:31 by rofuente          #+#    #+#             */
/*   Updated: 2024/07/22 13:05:30 by rofuente         ###   ########.fr       */
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

static int	red_cross(t_game *game)
{
	(void)game;
	// if (game->win != NULL && game->mlx != NULL)
	mlx_destroy_window(game->mlx, game->win);
	// free todo game
	// ft_free_mtx(game->map.map);
	exit (EXIT_SUCCESS);
}

static void	ft_strat(t_game *game, char *map)
{
	ft_read_map(game, map);
	game->mlx = mlx_init();
	if (!game->mlx)
		ft_error("Failed to open MLX\n");
	game->win = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	if (!game->win)
		ft_error("Failed to load window\n");
	all_xpm(game);
	mlx_key_hook(game->win, ft_key, &game);
	mlx_hook(game->win, 17, 0, red_cross, &game);
	mlx_loop_hook(game->mlx, &ft_player, (void *)game);
	mlx_loop(game->mlx);
}

static void	ft_cub(char **argv)
{
	ft_check_pname(argv[0], "./cub3D");
	ft_check_extension(argv[1], ".cub");
}

int	main(int argc, char **argv)
{
	t_game game;

	if (argc == 2)
	{
		ft_cub(argv);
		ft_strat(&game, argv[1]);
	}
	else
		ft_error("Please run: ./cub3D [map route].cub");
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:33:45 by rofuente          #+#    #+#             */
/*   Updated: 2024/06/24 17:54:47 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	ft_dir_n(t_game *game)
{
	game->player.dirX = -1;
	game->player.dirY = 0;
	game->player.planeX = 0;
	game->player.planeY = 0.66;
	game->player.flag = 'N';
}

void	ft_dir_s(t_game *game)
{
	game->player.dirX = 1;
	game->player.dirY = 0;
	game->player.planeX = 0;
	game->player.planeY = -0.66;
	game->player.flag = 'S';
}

void	ft_dir_e(t_game *game)
{
	game->player.dirX = 0;
	game->player.dirY = 1;
	game->player.planeX = -0.66;
	game->player.planeY = 0;
	game->player.flag = 'E';
}

void	ft_dir_w(t_game *game)
{
	game->player.dirX = 0;
	game->player.dirY = -1;
	game->player.planeX = 0.66;
	game->player.planeY = 0;
	game->player.flag = 'W';
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_xpm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 13:47:40 by rofuente          #+#    #+#             */
/*   Updated: 2024/06/17 14:03:00 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

static void	*start_xpm(t_game *game, char *str)
{
	char	*r;
	void	*img;

	r = ft_strjoin(XPM_PATH, str);
	img = mlx_xpm_file_to_image(game->mlx, r,
			&game->img_width, &game->img_height);
	if (!img)
		ft_error("Failed to load XPM\n");
	free (r);
	return (img);
}

void	all_xpm(t_game *game)
{
	game->map.north = start_xpm(game,game->map.nroute);
	game->map.south = start_xpm(game,game->map.sroute);
	game->map.east = start_xpm(game,game->map.eroute);
	game->map.west = start_xpm(game,game->map.wroute);
}

void	print_img(t_game *game, void *img, int i, int j)
{
	mlx_put_image_to_window(game->mlx, game->win, img, i, j);
}

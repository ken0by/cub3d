/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 20:09:22 by ken0by            #+#    #+#             */
/*   Updated: 2024/07/22 13:42:00 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

t_vec	ft_rotate(t_vec v, float r)
{
	t_vec	tmp;

	tmp.x = cosf(r) * v.x - sinf(r) * v.y;
	tmp.y = sinf(r) * v.x + cosf(r) * v.y;
	v.x = tmp.x;
	v.y = tmp.y;
	return (tmp);
}

t_vec	ft_fxv(t_vec v, float f)
{
	t_vec	tmp;

	tmp.x = v.x * f;
	tmp.y = v.y * f;
	return (tmp);
}

t_vec	ft_add(t_vec v1, t_vec v2)
{
	t_vec	new;

	new.x = v1.x + v2.x;
	new.y = v1.y + v2.y;
	return (new);
}

void	ft_movement(t_game *game, int x)
{
	t_vec	tmp;
	char	*aux;

	tmp.x = game->pos.x;
	tmp.y = game->pos.y;
	if (x == 1 || x == 2)
		tmp = ft_add(game->pos , ft_fxv(ft_rotate(game->direction, -PI / 2), 0.05));
	if (x == 3)
		tmp = ft_add(game->pos , ft_fxv(ft_rotate(game->direction, -PI), 0.05));
	if (x == 4)
		tmp = ft_add(game->pos, ft_fxv(game->direction, 0.05));
	if (tmp.x < 0 || tmp.y < 0)
		return ;
	aux = game->map.map[(int)floorf(tmp.y)][(int)floorf(tmp.x)];
	if (aux == '1')
		return ;
	game->pos = tmp;
	print_map(game);
}

int	ft_key(int key, t_game *game)
{
	if (key == KEY_ESC)
		exit(EXIT_SUCCESS);
	if (key == ARROW_RIGHT)
		press_r(game);
	if (key == ARROW_LEFT)
		press_l(game);
	if (key == KEY_W)
		press_w(game);
	if (key == KEY_S)
		press_s(game);
	if (key == KEY_D)
		press_d(game);
	if (key == KEY_A)
		press_a(game);
	return (0);
}

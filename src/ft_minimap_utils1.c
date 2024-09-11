/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap_utils1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ken0by <ken0by@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 11:20:38 by ken0by            #+#    #+#             */
/*   Updated: 2024/09/11 11:34:45 by ken0by           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

static float dot_prod(t_vec v1, t_vec v2) {
    return v1.x * v2.x + v1.y * v2.y;
}


static t_vec	sub_v(t_vec v1, t_vec v2)
{
	t_vec	res;

	res.y = v1.y - v2.y;
	res.x = v1.x - v2.x;
	return (res);
}

static float	size_vect(t_vec v)
{
	t_vec	zero;
	float	res;
	t_vec	temp;

	zero.x = 0;
	zero.y = 0;
	temp = sub_v(v, zero);
	res = sqrtf(dot_prod(temp, temp));
	return (res);
}

static t_vec	f_x_v(float f, t_vec v)
{
	t_vec	res;

	res.x = v.x * f;
	res.y = v.y * f;
	return (res);
}

t_vec	norm_vect(t_vec v1)
{
	return (f_x_v(1 / size_vect(v1), v1));
}

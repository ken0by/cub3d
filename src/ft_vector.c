/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:07:51 by rofuente          #+#    #+#             */
/*   Updated: 2024/09/09 12:09:19 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

t_vec	rotate_vector(t_vec vec, float rad)
{
	t_vec	temp;

	temp.x = cosf(rad) * vec.x - sinf(rad) * vec.y;
	temp.y = sinf(rad) * vec.x + cosf(rad) * vec.y;
	vec.x = temp.x;
	vec.y = temp.y;
	return (temp);
}

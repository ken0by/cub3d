/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:20:38 by mpizzolo          #+#    #+#             */
/*   Updated: 2024/07/18 16:23:36 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_memmove(void *dst, const void *src, size_t n)
{
	// size_t	i;
	char	*d;
	char	*s;

	d = (char *)dst;
	s = (char *)src;
	// i = 0;
	if (!d && !s)
		return (NULL);
	if (dst > src)
	{
		while (n > 0)
		{
			d[n - 1] = s[n - 1];
			n--;
		}
	}
	else
	{
		ft_memcpy(d, s, n);
	}
	return (dst);
}

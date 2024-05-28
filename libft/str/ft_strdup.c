/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:29:49 by rofuente          #+#    #+#             */
/*   Updated: 2023/03/28 13:12:51 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dst;
	int		x;

	dst = malloc(sizeof(char) * ft_strlen((char *)s1) + 1);
	if (!dst)
	{
		free (dst);
		return (0);
	}
	x = 0;
	while (s1[x])
	{
		dst[x] = s1[x];
		x++;
	}
	dst[x] = '\0';
	return (dst);
}

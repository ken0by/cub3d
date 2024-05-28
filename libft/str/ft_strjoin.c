/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodro <rodro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:24:38 by rofuente          #+#    #+#             */
/*   Updated: 2023/05/11 14:41:25 by rodro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*r;
	int		x;
	int		y;

	if (!s1)
		r = malloc(sizeof(char) * (ft_strlen((char *)s2)) + 1);
	else
		r = malloc(sizeof(char) * (ft_strlen((char *)s1)
					+ ft_strlen((char *)s2)) + 1);
	if (!r)
		return (NULL);
	x = 0;
	y = 0;
	while (s1[y])
		r[x++] = s1[y++];
	y = 0;
	while (s2[y])
		r[x++] = s2[y++];
	r[x] = '\0';
	return (r);
}

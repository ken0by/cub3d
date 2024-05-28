/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 12:26:39 by rofuente          #+#    #+#             */
/*   Updated: 2023/03/28 13:13:07 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char ))
{
	char	*r;
	int		x;

	x = 0;
	while (s[x])
		x++;
	r = malloc(sizeof(char) * x + 1);
	if (!r)
		return (NULL);
	x = 0;
	while (s[x])
	{
		r[x] = (*f)(x, s[x]);
		x++;
	}
	r[x] = '\0';
	return (r);
}

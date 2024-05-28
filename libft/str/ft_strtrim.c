/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:35:49 by rofuente          #+#    #+#             */
/*   Updated: 2023/03/28 13:13:21 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	ft_start(char const *s1, char const *set)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (set[y])
	{
		if (s1[x] == set[y])
		{
			y = 0;
			x++;
		}
		else
			y++;
	}
	return (x);
}

static int	ft_end(char const *s1, char const *set)
{
	int	j;
	int	y;

	j = 0;
	while (s1[j])
		j++;
	j--;
	y = 0;
	while (set[y])
	{
		if (s1[j] == set[y])
		{
			y = 0;
			j--;
		}
		else
			y++;
	}
	j++;
	return (j);
}

static char	*ft_fill(int x, int j, char const *s1, char *r)
{
	int		y;

	if (x > j)
		r = malloc(sizeof(char) * 1);
	else
		r = malloc(sizeof(char) * (j - x) + 1);
	if (!r)
		return (NULL);
	y = 0;
	while (x < j)
		r[y++] = s1[x++];
	r[y] = '\0';
	return (r);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*r;
	int		x;
	int		j;

	r = NULL;
	if (s1[0] == '\0')
	{
		r = malloc(sizeof(char) * 1);
		if (!r)
		{
			free (r);
			return (0);
		}
		r[0] = '\0';
		return (r);
	}
	x = ft_start(s1, set);
	j = ft_end(s1, set);
	return (ft_fill(x, j, s1, r));
}

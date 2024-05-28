/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodro <rodro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:47:42 by rofuente          #+#    #+#             */
/*   Updated: 2023/04/01 21:27:00 by rodro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	ft_count(char const *s, char c)
{
	int	x;
	int	count;

	x = 0;
	count = 0;
	while (s && s[x])
	{
		if (s[x] != c)
		{
			count++;
			while (s[x] != c && s[x])
				x++;
		}
		else
			x++;
	}
	return (count);
}

static int	ft_wsize(char const *s, char c, int x)
{
	int	k;

	k = 0;
	while (s[x] != c && s[x])
	{
		k++;
		x++;
	}
	return (k);
}

static void	ft_malloc_free(char **r, int y)
{
	while (y-- > 0)
		free (r[y]);
	free (r);
}

char	**ft_split(char const *s, char c)
{
	char	**r;
	int		x;
	int		y;
	int		j;

	x = 0;
	y = -1;
	r = malloc(sizeof(char *) * (ft_count(s, c) + 1));
	if (!r)
		return (NULL);
	while (++y < ft_count(s, c))
	{
		while (s[x] == c)
			x++;
		j = ft_wsize(s, c, x);
		r[y] = ft_substr(s, x, j);
		if (!r[y])
		{
			ft_malloc_free(r, y);
			return (NULL);
		}
		x += j;
	}
	r[y] = 0;
	return (r);
}

/* int main()
{
	char **r;
	int x;
	r = ft_split("  Hola que tal    broo   ", ' ');
	x = 0;
	while (r[x] != NULL)
	{
		printf("%s\n", r[x]);
		x++;
	}
	printf("%s\n", r[x]);
	printf("%s\n", r[x+1]);

	return (0);
} */

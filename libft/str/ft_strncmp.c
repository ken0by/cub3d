/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:07:04 by rofuente          #+#    #+#             */
/*   Updated: 2023/03/28 13:13:12 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	x;
	int		k;

	x = 0;
	k = 0;
	while ((x < n) && s1[x] && s2[x])
	{
		if (s1[x] == s2[x])
			x++;
		else
		{
			k = ((unsigned char)s1[x] - (unsigned char)s2[x]);
			return (k);
		}
	}
	if (x < n)
	{
		if ((s1[x] == '\0') || (s2[x] == '\0'))
			k = ((unsigned char)s1[x] - (unsigned char)s2[x]);
	}
	return (k);
}

// int main()
// {
// 	char a[] = "\200";
// 	char b[] = "\0";
// 	printf("%d\n", strncmp(a, b, 1));
// 	printf("%d\n", ft_strncmp(a, b, 1));
// 	return (0);
// }

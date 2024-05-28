/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:21:39 by rofuente          #+#    #+#             */
/*   Updated: 2023/03/28 13:12:08 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			x;
	unsigned char	*a;
	unsigned char	*b;

	a = (unsigned char *)s1;
	b = (unsigned char *)s2;
	x = 0;
	while (x < n)
	{
		if (a[x] == b[x])
			x++;
		else
			return (a[x] - b[x]);
	}
	return (0);
}

// int main()
// {
// 	char a[] = "Hola que tal?";
// 	char b[] = "Hola que tal ";
// 	printf("%d\n", memcmp(a, b, 13));
// 	printf("%d\n", ft_memcmp(a, b, 13));
// 	return (0);
// }

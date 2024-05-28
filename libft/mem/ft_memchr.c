/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:05:21 by rofuente          #+#    #+#             */
/*   Updated: 2023/03/28 13:12:06 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			x;
	unsigned char	*a;
	unsigned char	z;

	z = (unsigned char)c;
	a = (unsigned char *)s;
	x = 0;
	while (x < n)
	{
		if (a[x] == z)
			return (&a[x]);
		x++;
	}
	return (0);
}

// int main()
// {
// 	char s[] = "/|\x12\xff\x09\x42\042\42|\\";
// 	int a = '\x42';
// 	printf("%s\n", memchr(s, a, 10));
// 	printf("%s\n", ft_memchr(s, a, 10));
// 	return (0);
// }

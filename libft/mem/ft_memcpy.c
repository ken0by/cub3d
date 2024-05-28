/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:06:44 by rofuente          #+#    #+#             */
/*   Updated: 2023/03/28 13:12:10 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	x;
	char	*a;
	char	*b;

	a = (char *)src;
	b = (char *)dst;
	x = 0;
	if ((a == NULL && b == NULL))
		return (0);
	while (x < n)
	{
		b[x] = a[x];
		x++;
	}
	return (dst);
}

// int main()
// {
//     char s[40] = "Hola que tal?";
//     char *d = NULL;
//     int x;

//     x = '\0';
//     printf("%s\n", memcpy(d, s, x));
//     printf("%s\n", ft_memcpy(d, s, 0));
//     return (0);
// }

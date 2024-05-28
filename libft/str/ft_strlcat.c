/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:06:55 by rofuente          #+#    #+#             */
/*   Updated: 2023/03/28 13:12:59 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

unsigned long	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	x;
	size_t	j;
	size_t	k;

	k = ft_strlen(src);
	x = 0;
	while (dst[x] && x < dstsize)
		x++;
	j = 0;
	while (src[j] && (x + j + 1) < dstsize)
	{
		dst[x + j] = src[j];
		j++;
	}
	if (x < dstsize)
		dst[x + j] = '\0';
	return (x + k);
}

// int main()
// {
//     char src[50] = "Hola que tal?";
//     char src0[50] = "Hola que tal?";
//     char a[] = "Hola que";
//     char b[] = "Hola que";
//     int i;
//     int j;

//     i = strlcat(a, src, 3);
//     printf("%d\n", i);
//     printf("%s\n", a);
//     printf("%s\n", src);
//     j = ft_strlcat(b, src0, 3);
//     printf("%d\n", j);
//     printf("%s\n", b);
//     printf("%s\n", src0);
//     return (0);
// }

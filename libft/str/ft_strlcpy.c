/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:06:58 by rofuente          #+#    #+#             */
/*   Updated: 2023/03/28 13:13:02 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

unsigned long	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	x;
	size_t	a;

	a = 0;
	while (src[a])
		a++;
	x = 0;
	if (dstsize == 0)
		return (a);
	while (x < (dstsize - 1) && src[x])
	{
		dst[x] = src[x];
		x++;
	}
	dst[x] = '\0';
	return (a);
}

// int main()
// {
//     char str[50] = "Hola que tal?";
//     char *a = NULL;
// 	char *b = NULL;
//     int i;
//     int j;

//     i = strlcpy(a, str, 7);
//     printf("Esto es i: %d\n", i);
//     printf("%s\n", a);
//     j = ft_strlcpy(b, str, 7);
//     printf("Esto es j: %d\n", j);
//     printf("%s\n", b);
//     return (0);
// }

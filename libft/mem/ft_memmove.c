/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:06:47 by rofuente          #+#    #+#             */
/*   Updated: 2023/03/28 13:12:11 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	x;
	char	*a;
	char	*b;

	a = (char *)src;
	b = (char *)dst;
	if (dst == src)
		return (dst);
	x = 0;
	if (src < dst)
	{
		while (x < len--)
			b[len] = a[len];
	}
	else
	{
		while (x < len)
		{
			b[x] = a[x];
			x++;
		}
	}
	return (dst);
}

// int main()
// {
//     char a[50] = "Hola que tal?";
//     char *b;

//     printf("%s\n", memmove(b, a, 4));
//     printf("%s\n", ft_memmove(b, a, 4));
//     return (0);
// }

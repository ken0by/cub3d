/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:07:16 by rofuente          #+#    #+#             */
/*   Updated: 2023/03/28 13:13:18 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	flag;
	int	flag2;
	int	x;

	flag = 0;
	x = 0;
	while (s[x])
	{
		if (s[x] == (char)c)
			flag += 1;
		x++;
	}
	flag2 = 0;
	while (*s)
	{
		if (*s == (char)c)
			flag2 += 1;
		if ((flag2 == flag) && flag != 0)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (0);
}

// int main()
// {
//     char src[50] = "Hola que tal?";
//     char src0[50] = "Hola que tal?";
//     int x;

//     x = '\0';
//     printf("%s\n", strrchr(src, x));
//     printf("%s\n", ft_strrchr(src0, x));
//     return (0);
// }

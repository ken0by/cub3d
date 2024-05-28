/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:06:50 by rofuente          #+#    #+#             */
/*   Updated: 2023/03/28 13:12:22 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	int				x;
	unsigned char	*str;

	str = (unsigned char *)b;
	x = 0;
	while (x < (int)len)
	{
		str[x] = c;
		x++;
	}
	return (str);
}

// int main()
// {
//     char str[50] = "Hola que tal";

//     printf("%s\n", memset(str, '$', 4));
//     printf("%s\n", ft_memset(str, '$', 4));
//     return (0);
// }

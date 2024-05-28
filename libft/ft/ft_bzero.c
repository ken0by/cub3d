/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:06:14 by rofuente          #+#    #+#             */
/*   Updated: 2023/03/28 13:09:34 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_bzero(void *s, size_t n)
{
	int		x;
	char	*str;

	str = (char *)s;
	if (n == '0')
		return ;
	x = 0;
	while (x < (int)n)
	{
		str[x] = '\0';
		x++;
	}
	return ;
}

// int main()
// {
//     char str[50] = "Hola que tal?";

//     printf("%s\n", bzero(str, 1));
//     ft_bzero(str, 1);
//     printf("%s\n", str);
//     return (0);
// }

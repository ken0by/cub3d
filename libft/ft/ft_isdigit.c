/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:06:33 by rofuente          #+#    #+#             */
/*   Updated: 2023/03/28 13:09:47 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_isdigit(int x)
{
	int	flag;

	flag = 1;
	if (x < '0' || x > '9')
		flag = 0;
	return (flag);
}

// int main()
// {
//     int x;

//     /*Si lo pones con '' es el numero, sin las '' pasas el valor ascii*/
//     x = 56;
//     printf("%d\n", isdigit(x));
//     printf("%d\n", ft_isdigit(x));
//     return (0);
// }

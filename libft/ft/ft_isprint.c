/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:06:36 by rofuente          #+#    #+#             */
/*   Updated: 2023/03/28 13:09:49 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_isprint(int x)
{
	int	flag;

	flag = 1;
	if (x < 32 || x > 126)
		flag = 0;
	return (flag);
}

// int main()
// {
//     int x;

//     x = '~';
//     printf("%d\n", isprint(x));
//     printf("%d\n", ft_isprint(x));
//     return (0);
// }

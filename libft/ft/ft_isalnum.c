/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:06:23 by rofuente          #+#    #+#             */
/*   Updated: 2023/03/28 13:09:39 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_isalnum(int x)
{
	int	flag;

	flag = 1;
	if (x < '0' || (x > '9' && x < 'A')
		|| (x > 'Z' && x < 'a') || x > 'z')
		flag = 0;
	return (flag);
}

// int main()
// {
//     int x;

//     x = '2';
//     printf("%d\n", isalnum(x));
//     printf("%d\n", ft_isalnum(x));
//     return (0);
// }

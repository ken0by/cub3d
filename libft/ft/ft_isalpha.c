/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:06:27 by rofuente          #+#    #+#             */
/*   Updated: 2023/03/28 13:09:42 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_isalpha(int x)
{
	int	flag;

	flag = 1;
	if (x < 'A' || (x > 'Z' && x < 'a') || x > 'z')
		flag = 0;
	return (flag);
}

// int main()
// {
//     int x;

//     x = 'm';
//     printf("%d\n", isalpha(x));
//     printf("%d\n", ft_isalpha(x));
//     return (0);
// }

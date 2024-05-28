/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 21:58:27 by rofuente          #+#    #+#             */
/*   Updated: 2023/03/28 13:09:51 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static void	ft_isneg(int *n, int *neg)
{
	if (*n < 0)
	{
		*n *= -1;
		*neg = 1;
	}
}

static char	*ft_maxmin(int n, int len, char *str, int neg)
{
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 2147483647)
		return (ft_strdup("2147483647"));
	else
	{
		while (len--)
		{
			str[len] = n % 10 + 48;
			n = n / 10;
		}
		if (neg == 1)
			str[0] = '-';
		return (str);
	}
	return (0);
}

static int	ft_len(int x, int len)
{
	x /= 10;
	while (x)
	{
		x /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		neg;
	int		len;
	int		x;
	char	*str;

	if (n == -2147483648 || n == 2147483647)
		return (ft_maxmin(n, 0, "hola", 0));
	x = n;
	neg = 0;
	ft_isneg(&n, &neg);
	len = ft_len(x, 2);
	len = len + neg;
	str = malloc(sizeof(char) * len);
	if (!str)
		return (NULL);
	str[--len] = '\0';
	return (ft_maxmin(n, len, str, neg));
}

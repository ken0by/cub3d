/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:47:56 by rofuente          #+#    #+#             */
/*   Updated: 2023/03/28 13:13:24 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*a;
	size_t		x;

	if (!s)
		return (NULL);
	if (ft_strlen(s) <= start)
		return (ft_strdup(""));
	if (ft_strlen(&s[start]) < len)
		len = ft_strlen(&s[start]);
	a = malloc(sizeof(char) * (len + 1));
	if (!a)
		return (NULL);
	x = 0;
	while (x < len && s[start])
		a[x++] = s[start++];
	a[x] = '\0';
	return (a);
}

/* int main()
{
	printf("%s\n", ft_substr("", 0, 0));
	return (0);
} */

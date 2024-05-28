/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:34:53 by rofuente          #+#    #+#             */
/*   Updated: 2023/03/28 13:13:16 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	x;
	size_t	y;
	char	*r;

	x = 0;
	if (haystack && needle[0] == '\0')
		return ((char *)haystack);
	if (len == 0)
		return (0);
	while (x < len && haystack[x])
	{
		y = 0;
		while (haystack[x + y] == needle[y] && x + y < len && haystack[x + y])
			y++;
		if (!needle[y])
		{
			r = (char *)(haystack + x);
			return (r);
		}
		x++;
	}
	return (0);
}

// int main()
// {
// 	char a[] = "see FF your FF return FF now ";
// 	char b[] = "FF";
// 	size_t max = strlen(a);
// 	//printf("%s\n", strnstr(a, b, max));
// 	printf("%s\n", ft_strnstr(a, b, max));
// 	return (0);
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 20:13:20 by mpizzolo          #+#    #+#             */
/*   Updated: 2024/07/18 16:24:01 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		s_length;
	// int		i;

	s_length = ft_strlen(s1) + 1;
	s2 = (char *)malloc(sizeof(char) * s_length);
	if (!s2)
		return (NULL);
	// i = 0;
	ft_memcpy(s2, s1, s_length);
	return (s2);
}

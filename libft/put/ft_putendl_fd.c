/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:46:37 by rofuente          #+#    #+#             */
/*   Updated: 2023/03/28 13:12:36 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	x;

	x = 0;
	while (s[x])
	{
		write(fd, &s[x], 1);
		x++;
	}
	write(fd, "\n", 1);
	return ;
}

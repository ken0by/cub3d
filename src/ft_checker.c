/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ken0by <ken0by@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 10:52:09 by rofuente          #+#    #+#             */
/*   Updated: 2024/09/16 11:22:37 by ken0by           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

static int	ft_rgb(char **texture)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (!texture[i])
		{
			ft_printf("MISSING RGB VALUE\n");
			return (0);
		}
		if (atoi(texture[i]) < 0 || atoi(texture[i]) > 255)
		{
			ft_printf("NOT VALID RGB VALUES\n");
			return (0);
		}
		i++;
	}
	return (1);
}

static int	ft_xpm(char *path)
{
	size_t	len;

	len = ft_strlen(path);
	if ((path[len - 3] != 'x' || path[len - 2] != 'p'
			|| path[len - 1] != 'm'
			|| path[len - 4] != '.'))
		return (0);
	return (1);
}

static int	ft_dir(char *path)
{
	int	fd;

	fd = open(path, O_DIRECTORY);
	if (fd >= 0)
	{
		close (fd);
		return (1);
	}
	return (0);
}

static int	ft_file(char *texturepath)
{
	int	fd;

	if (ft_dir(texturepath))
	{
		ft_printf("PATH IS A DIRECTORY\n");
		return (0);
	}
	fd = open(texturepath, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("CANNOT OPEN FILE\n");
		return (0);
	}
	close(fd);
	if (!ft_xpm(texturepath))
	{
		ft_printf("FILE IS NOT XPM\n");
		return (0);
	}
	return (1);
}

int	ft_check_inf(t_texture textures)
{
	if (!textures.n || !textures.s || !textures.e
		|| !textures.w || !textures.f || !textures.c)
	{
		ft_printf("MISSING TEXTURES\n");
		return (0);
	}
	if (ft_file(textures.n) == 0
		|| ft_file(textures.s) == 0
		|| ft_file(textures.w) == 0
		|| ft_file(textures.e) == 0
		|| ft_rgb(textures.f) == 0
		|| ft_rgb(textures.c) == 0)
		return (0);
	return (1);
}

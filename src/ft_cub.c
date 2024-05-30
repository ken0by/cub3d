/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 13:07:31 by rofuente          #+#    #+#             */
/*   Updated: 2024/05/30 14:57:46 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

static void	ft_check_extension(char *file, char *ext)
{
	int	i;
	int	j;

	i = ft_strlen(file) - ft_strlen(ext);
	j = 0;
	while (file[i + j] && ext[j])
	{
		if (file[i + j] == ext[j])
			j++;
		else
		{
			ft_printf("Map file extetion is not '.cub'\n");
			exit(1);
		}
	}
}

static void	ft_check_pname(char *pro, char *name)
{
	int	i;

	i = 0;
	while (pro[i] && name[i])
	{
		if (pro[i] == name[i])
			i++;
		else
		{
			ft_printf("Program name is not './cub3D'\n");
			exit(1);
		}
	}
}

static void	ft_cub(char **argv)
{
	ft_check_pname(argv[0], "./cub3D");
	ft_check_extension(argv[1], ".cub");
}

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		ft_printf("Error requieres map.cub\n");
		return (1);
	}
	if (argc == 2)
	{
		ft_cub(argv);
	}
	ft_printf("Nice\n");
	return (0);
}

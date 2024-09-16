/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ken0by <ken0by@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 10:16:26 by rofuente          #+#    #+#             */
/*   Updated: 2024/09/12 11:27:19 by ken0by           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

static int	ft_get_info(t_game *game, char **file)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_data.lines)
	{
		j = 0;
		while (file[i][j] == ' ' || file[i][j] == '\t' || file[i][j] == '\n')
			j++;
		if (ft_isalpha(file[i][j]))
		{
			ft_info(game, file[i], j);
			i++;
		}
		else if (ft_isdigit(file[i][j]))
		{
			ft_cpy_map(game, file, i);
			return (1);
		}
		else
			i++;
	}
	return (0);
}

static int	ft_cpy_file(t_game *game, char *file)
{
	game->map_data.lines = ft_count(file);
	if (!game->map_data.lines)
		return (0);
	game->map_data.map_cpy = ft_calloc(game->map_data.lines
			+ 1, sizeof(char *));
	if (!game->map_data.map_cpy)
		return (0);
	game->map_data.fd = open(file, O_RDONLY);
	if (game->map_data.fd < 0)
		return (0);
	ft_cpy(game);
	close(game->map_data.fd);
	return (1);
}

static int	ft_check_extension(char *file)
{
	int	fd;

	if (!ft_strnstr(file, ".cub", ft_strlen(file)))
		return (0);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	close(fd);
	return (1);
}

int	ft_parse(t_game *game, char **argv)
{
	if (!ft_check_extension(argv[1]))
		return (0);
	if (!ft_cpy_file(game, argv[1]))
		return (0);
	ft_get_info(game, game->map_data.map_cpy);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ken0by <ken0by@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 10:23:11 by rofuente          #+#    #+#             */
/*   Updated: 2024/09/12 11:28:47 by ken0by           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

static int	ft_map_width(char **file, int i)
{
	int	j;

	j = 0;
	while(file[i][j])
	{
		if (file[i][j] != '1' && file[i][j] != '0' && file[i][j] != ' '
		&& file[i][j] != '\t' && file[i][j] != '\r'
		&& file[i][j] != '\v' && file[i][j] != '\f')
			break ;
		j++;
	}
	return (j);
}

void	ft_cpy_map(t_game *game, char **file, int start)
{
	int	i;

	i = 0;
	game->map_width = ft_map_width(file, start);
	game->map_height = ft_map_height(file, start);
	game->map = ft_calloc(game->map_height + 1, sizeof(char *));
	if (!game->map)
		return ;
	while (i < game->map_height)
	{
		game->map[i] = ft_strdup(game->map_data.map_cpy[start]);
		i++;
		start++;
	}
}

void	ft_info(t_game *game, char *line, int j)
{
	if (line[j + 1] && ft_isalpha(line[j + 1]))
		ft_textures(game, line, j);
	else
		ft_colors(game, line, j);
}

void	ft_cpy(t_game *game)
{
	int		i;
	int		row;
	int		col;
	char	*line;

	i = 0;
	row = 0;
	col = 0;
	line = get_next_line(game->map_data.fd);
	while (line != NULL)
	{
		game->map_data.map_cpy[row]
			= ft_calloc(ft_strlen(line) + 1, sizeof(char));
		if (!game->map_data.map_cpy[row])
			return ;
		while (line[i] != '\0')
			game->map_data.map_cpy[row][col++] = line[i++];
		game->map_data.map_cpy[row++][col] = '\0';
		col = 0;
		i = 0;
		free(line);
		line = get_next_line(game->map_data.fd);
	}
	game->map_data.map_cpy[row] = NULL;
}

int	ft_count(char *file)
{
	int		fd;
	char	*line;
	int		count;

	count = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	while (line != NULL)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}

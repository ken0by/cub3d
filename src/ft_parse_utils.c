/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 10:23:11 by rofuente          #+#    #+#             */
/*   Updated: 2024/09/09 13:50:15 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

static int	count_map_width(char **file, int i)
{
	int	start;
	int	j;

	start = i;
	while (file[i])
	{
		j = 0;
		while (file[i][j] == ' ' || file[i][j] == '\t' || file[i][j] == '\r'
		|| file[i][j] == '\v' || file[i][j] == '\f')
			j++;
		if (file[i][j] != '1')
			break ;
		i++;
	}
	return (i - start);
}

void	copy_map(t_game *game, char **file, int start)
{
	int	i;

	i = 0;
	game->map_width = count_map_width(file, start);
	game->map_height = count_map_height(file, start);
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

void	copy_info(t_game *game, char *line, int j)
{
	if (line[j + 1] && ft_isalpha(line[j + 1]))
		copy_textures(game, line, j);
	else
		copy_colors(game, line, j);
}

void	fill_copy(t_game *game)
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

int	count_lines(char *file)
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

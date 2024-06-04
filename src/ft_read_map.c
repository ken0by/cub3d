/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:50:41 by rofuente          #+#    #+#             */
/*   Updated: 2024/06/04 16:28:41 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

static void	ft_cpymap(t_game *game)
{
	int	i;
	int	j;
	int	k;
	int	len;

	game->map.cpy = ft_calloc(game->map.height + 1, sizeof(char *));
	if (!game->map.cpy)
		return ;
	i = 0;
	k = 0;
	while (i < game->map.height)
	{
		len = game->map.width + 1;
		game->map.cpy[i] = ft_calloc(len, sizeof(char));
		if (!game->map.cpy[i])
			return ;
		j = 0;
		while (j < game->map.width)
			game->map.cpy[i][j++] = game->map.line[k++];
		game->map.cpy[i][j] = '\0';
		i++;
	}
}

void	ft_read_map(t_game *game, char *file)
{
	int	fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd <= 0)
		ft_error("Failed to open file\n");
	line = get_next_line(fd);
	if (!line)
		ft_error("Empty map!\n");
	if (line[0] == '\n')
		ft_error("First line is empty!\n");
	game->map.height = 0;
	game->map.width = ft_strlen(line) - 1;
	game->map.line = ft_strdup_no_nl(line);
	free (line);
	while (line)
	{
		line = get_next_line(fd);
		game->map.line = ft_strjoin_no_nl(game->map.line, line);
		game->map.height++;
	}
	close (fd);
	ft_cpymap(game);
	int i = -1;
	while(game->map.cpy[++i])
			ft_printf("%s\n", game->map.cpy[i]);
	i = -1;
	while(game->map.cpy[++i])
		free(game->map.cpy[i]);
	free(game->map.cpy);
}

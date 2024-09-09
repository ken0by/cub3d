/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_uitls1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 10:26:29 by rofuente          #+#    #+#             */
/*   Updated: 2024/09/09 10:30:15 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

static char	**get_color(char *line, int j)
{
	int		i;
	int		len;
	char	*temp;
	char	*rgb_values;
	char	**rgb_array;

	i = 0;
	len = 0;
	while (line[j] && (line[j] == ' ' || line[j] == '\t'))
		j++;
	i = j;
	while (line[i] && (line[i] != ' ' || line[i] != '\t'))
	{
		len++;
		i++;
	}
	temp = ft_substr(line, j, len);
	rgb_values = ft_strdup_no_nl(temp);
	free(temp);
	rgb_array = ft_split(rgb_values, ',');
	free(rgb_values);
	return (rgb_array);
}

static char	*get_texture(char *line, int j)
{
	int		i;
	int		len;
	char	*temp;
	char	*texture;

	i = 0;
	len = 0;
	while (line[j] && (line[j] == ' ' || line[j] == '\t'))
		j++;
	i = j;
	while (line[i] && (line[i] != ' ' || line[i] != '\t'))
	{
		len++;
		i++;
	}
	temp = ft_substr(line, j, len);
	texture = ft_strdup_no_nl(temp);
	free(temp);
	return (texture);
}

void	copy_colors(t_game *game, char *line, int j)
{
	if (line[j] == 'F')
	{
		if (game->tex.f)
			ft_error(game, "Duplicated floor texture\n");
		game->tex.f = get_color(line, j + 1);
	}
	if (line[j] == 'C')
	{
		if (game->tex.c)
			ft_error(game, "Duplicated ceiling texture\n");
		game->tex.c = get_color(line, j + 1);
	}
}

void	copy_textures(t_game *game, char *line, int j)
{
	if (line[j] == 'N' && line[j + 1] == 'O')
	{
		if (game->tex.n)
			ft_error(game, "Duplicated north texture\n");
		game->tex.n = get_texture(line, j + 2);
	}
	if (line[j] == 'S' && line[j + 1] == 'O')
	{
		if (game->tex.s)
			ft_error(game, "Duplicated south texture\n");
		game->tex.s = get_texture(line, j + 2);
	}
	if (line[j] == 'E' && line[j + 1] == 'A')
	{
		if (game->tex.e)
			ft_error(game, "Duplicated east texture\n");
		game->tex.e = get_texture(line, j + 2);
	}
	if (line[j] == 'W' && line[j + 1] == 'E')
	{
		if (game->tex.w)
			ft_error(game, "Duplicated west texture\n");
		game->tex.w = get_texture(line, j + 2);
	}
}

int	count_map_height(char **file, int i)
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_utils_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ken0by <ken0by@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 10:26:29 by rofuente          #+#    #+#             */
/*   Updated: 2024/09/16 11:28:21 by ken0by           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

static char	**ft_cpy_colors(char *line, int j)
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
	rgb_values = ft_strdup_nl(temp);
	free(temp);
	rgb_array = ft_split(rgb_values, ',');
	free(rgb_values);
	return (rgb_array);
}

static char	*ft_cpy_textures(char *line, int j)
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
	texture = ft_strdup_nl(temp);
	free(temp);
	return (texture);
}

void	ft_colors(t_game *game, char *line, int j)
{
	if (line[j] == 'F')
	{
		if (game->tex.f)
			ft_error(game, "Duplicated floor texture\n");
		game->tex.f = ft_cpy_colors(line, j + 1);
	}
	if (line[j] == 'C')
	{
		if (game->tex.c)
			ft_error(game, "Duplicated ceiling texture\n");
		game->tex.c = ft_cpy_colors(line, j + 1);
	}
}

void	ft_textures(t_game *game, char *line, int j)
{
	if (line[j] == 'N' && line[j + 1] == 'O')
	{
		if (game->tex.n)
			ft_error(game, "Duplicated north texture\n");
		game->tex.n = ft_cpy_textures(line, j + 2);
	}
	if (line[j] == 'S' && line[j + 1] == 'O')
	{
		if (game->tex.s)
			ft_error(game, "Duplicated south texture\n");
		game->tex.s = ft_cpy_textures(line, j + 2);
	}
	if (line[j] == 'E' && line[j + 1] == 'A')
	{
		if (game->tex.e)
			ft_error(game, "Duplicated east texture\n");
		game->tex.e = ft_cpy_textures(line, j + 2);
	}
	if (line[j] == 'W' && line[j + 1] == 'E')
	{
		if (game->tex.w)
			ft_error(game, "Duplicated west texture\n");
		game->tex.w = ft_cpy_textures(line, j + 2);
	}
}

int	ft_map_height(char **file, int start)
{
	int	i;
	int	j;

	i = start;
	while (file[i])
	{
		if (file[i][0] != '1' && file[i][0] != '0' && file[i][0] != ' '
		&& file[i][0] != '\t' && file[i][0] != '\r'
		&& file[i][0] != '\v' && file[i][0] != '\f')
			break ;
		i++;
	}
	j = i - start;
	return (j);
}

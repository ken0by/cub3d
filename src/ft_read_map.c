/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:50:41 by rofuente          #+#    #+#             */
/*   Updated: 2024/06/12 13:19:56 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

/* COPIA SOLO EL MAPA */
/* static char	**ft_cpy_map(char **map, int i)
{

} */

static void	ft_rgb_floor(t_game *game, char *map)
{
	int		i;
	int		j;
	char	tmp[4];

	i = 2;
	j = 0;
	while (map[i] != ',')
	{
		tmp[j] = map[i];
		j++;
		i++;
	}
	tmp[j] = '\0';
	game->map.floor.r = ft_atoi(tmp);
	j = 0;
	i++;
	while (map[i] != ',')
	{
		tmp[j] = map[i];
		j++;
		i++;
	}
	tmp[j] = '\0';
	game->map.floor.g = ft_atoi(tmp);
	j = 0;
	i++;
	while (map[i] != '\n')
	{
		tmp[j] = map[i];
		j++;
		i++;
	}
	tmp[j] = '\0';
	game->map.floor.b = ft_atoi(tmp);
}

static void	ft_rgb_ceiling(t_game *game, char *map)
{
	int		i;
	int		j;
	char	tmp[4];

	i = 2;
	j = 0;
	while (map[i] != ',')
	{
		tmp[j] = map[i];
		j++;
		i++;
	}
	tmp[j] = '\0';
	game->map.ceiling.r = ft_atoi(tmp);
	j = 0;
	i++;
	while (map[i] != ',')
	{
		tmp[j] = map[i];
		j++;
		i++;
	}
	tmp[j] = '\0';
	game->map.ceiling.g = ft_atoi(tmp);
	j = 0;
	i++;
	while (map[i] != '\n')
	{
		tmp[j] = map[i];
		j++;
		i++;
	}
	tmp[j] = '\0';
	game->map.ceiling.b = ft_atoi(tmp);
}

static char	*ft_cpy_route(char *route)
{
	char	*cpy;
	int		i;
	int		j;
	int		k;

	i = 0;
	while (route[i] != '.')
		i++;
	i--;
	k = i;
	j = 0;
	while (route[++i])
		j++;
	cpy = malloc(sizeof(char) * (j));
	i = 0;
	while (route[++k] != '\n')
	{
		cpy[i] = route[k];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

/* GUARDAR LAS RUTAS DE LAS TEXTURAS */
static void	ft_route_save(t_game *game)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	while (game->map.cpy[++i])
	{
		if (game->map.cpy[i][0] == 'N' && game->map.cpy[i][1] == 'O')
		{
			game->map.nroute = ft_cpy_route(game->map.cpy[i]);
			j = i;
		}
		if (game->map.cpy[i][0] == 'S' && game->map.cpy[i][1] == 'O')
		{
			game->map.sroute = ft_cpy_route(game->map.cpy[i]);
			j = i;
		}
		if (game->map.cpy[i][0] == 'E' && game->map.cpy[i][1] == 'A')
		{
			game->map.eroute = ft_cpy_route(game->map.cpy[i]);
			j = i;
		}
		if (game->map.cpy[i][0] == 'W' && game->map.cpy[i][1] == 'E')
		{
			game->map.wroute = ft_cpy_route(game->map.cpy[i]);
			j = i;
		}
	}
	i = -1;
	while (game->map.cpy[++i])
	{
		if (game->map.cpy[i][0] == 'F' && game->map.cpy[i][1] == ' ')
		{
			ft_rgb_floor(game, game->map.cpy[i]);
			k = i;
		}
		if (game->map.cpy[i][0] == 'C' && game->map.cpy[i][1] == ' ')
		{
			ft_rgb_ceiling(game, game->map.cpy[i]);
			k = i;
		}
	}
	if (j > k)
		i = j + 1;
	else
		i = k + 1;
	while (game->map.cpy[i][0] == '\n')
		i++;
	// game->map.map = ft_cpy_map(game->map.cpy, i);
	// DESPUES DE ESTO HAY Q BORRAR LA COPIA ORIGINAL
	printf("n-> %s\n", game->map.nroute);
	printf("s-> %s\n", game->map.sroute);
	printf("e-> %s\n", game->map.eroute);
	printf("w-> %s\n", game->map.wroute);
	printf("floor-> r: %d, g: %d, b: %d\n", game->map.floor.r, game->map.floor.g, game->map.floor.b);
	printf("ceiling-> r: %d, g: %d, b: %d\n", game->map.ceiling.r, game->map.ceiling.g, game->map.ceiling.b);
}

void	ft_read_map(t_game *game, char *file)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd <= 0)
		ft_error("Failed to open file\n");
	line = get_next_line(fd);
	if (!line)
		ft_error("Empty map!\n");
	i = 1;
	while (line)
	{
		free (line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
	close (fd);
	game->map.cpy = malloc(sizeof(char *) * (i + 2));
	int	j;
	int	k;
	j = 0;
	fd = open(file, O_RDONLY);
	while (j <= i)
	{
		line = get_next_line(fd);
		game->map.cpy[j] = malloc(sizeof(char) * (ft_strlen(line) + 2));
		k = 0;
		while (k < (int)ft_strlen(line))
		{
			game->map.cpy[j][k] = line[k];
			k++;
		}
		game->map.cpy[j][k] = '\0';
		free(line);
		j++;
	}
	game->map.cpy[j] = '\0';
	ft_route_save(game);
	i = -1;
	while(game->map.cpy[++i])
			printf("%s", game->map.cpy[i]);
	i = -1;
	while(game->map.cpy[++i])
		free(game->map.cpy[i]);
	free(game->map.cpy);
}

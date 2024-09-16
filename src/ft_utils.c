/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ken0by <ken0by@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 10:48:15 by rofuente          #+#    #+#             */
/*   Updated: 2024/09/16 11:29:49 by ken0by           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	ft_print_inf(t_game *game)
{
	ft_printf("\n");
	if (game->tex.n)
		ft_printf("north texture is: %s\n", game->tex.n);
	if (game->tex.s)
		ft_printf("south texture is: %s\n", game->tex.s);
	if (game->tex.e)
		ft_printf("east texture is: %s\n", game->tex.e);
	if (game->tex.w)
		ft_printf("west texture is: %s\n", game->tex.w);
	if (game->tex.f)
	{
		ft_printf("\nfloor rgb value is: \n");
		ft_print_arr(game->tex.f);
	}
	if (game->tex.c)
	{
		ft_printf("ceiling rgb value is: \n");
		ft_print_arr(game->tex.c);
	}
}

void	ft_print_arr(char **array)
{
	int	i;

	i = 0;
	ft_printf("\n");
	while (array[i] != NULL)
	{
		ft_printf("%s\n", array[i]);
		i++;
	}
	ft_printf("\n");
}

void	ft_free_inf(t_game *game)
{
	if (game->tex.n)
		free(game->tex.n);
	if (game->tex.s)
		free(game->tex.s);
	if (game->tex.e)
		free(game->tex.e);
	if (game->tex.w)
		free(game->tex.w);
	if (game->tex.f)
		ft_free_arr(game->tex.f);
	if (game->tex.c)
		ft_free_arr(game->tex.c);
}

void	ft_free_arr(char **array)
{
	size_t	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	if (array)
	{
		free(array);
		array = NULL;
	}
}

char	*ft_strdup_nl(char *str)
{
	int		i;
	char	*duplicate;

	i = 0;
	duplicate = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!duplicate)
		return (NULL);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			break ;
		duplicate[i] = str[i];
		i++;
	}
	duplicate[i] = '\0';
	return (duplicate);
}

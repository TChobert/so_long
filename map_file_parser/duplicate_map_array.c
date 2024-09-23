/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicate_map_array.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:34:14 by tchobert          #+#    #+#             */
/*   Updated: 2024/09/23 16:35:01 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	fill_new_array(t_game_data game_data, char **new_array)
{
	size_t	i;

	i = 0;
	while (game_data.current_map_data.map_array[i] != NULL)
	{
		new_array[i] = ft_strdup(game_data.current_map_data.map_array[i]);
		if (new_array[i] == NULL)
		{
			ft_free_and_null(new_array);
			return ;
		}
		++i;
	}
}

static size_t	get_map_array_size(char **map_array)
{
	size_t	i;

	i = 0;
	while (map_array[i] != NULL)
	{
		++i;
	}
	return (i);
}

char	**duplicate_map_array(t_game_data game_data)
{
	char 	**new_array;
	size_t	array_size;

	array_size = get_map_array_size(game_data.current_map_data.map_array);
	new_array = (char **)malloc(sizeof(char *) * (array_size + 1));
	if (new_array != NULL)
	{
		new_array[array_size] = NULL;
		fill_new_array(game_data, new_array);
	}
	return (new_array);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 13:26:13 by tchobert          #+#    #+#             */
/*   Updated: 2024/09/25 15:12:17 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	flood_fill_recursive_calls(t_game_data *game_data,
				char **duplicated_map, size_t x, size_t y)
{
	if (flood_fill(game_data, duplicated_map, x + 1, y) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	if (flood_fill(game_data, duplicated_map, x - 1, y) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	if (flood_fill(game_data, duplicated_map, x, y + 1) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	if (flood_fill(game_data, duplicated_map, x, y - 1) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int flood_fill(t_game_data *game_data, char **duplicated_map,
						size_t x, size_t y)
{
	if (x < 0 || x >= game_data->current_map_data.map_rows_number || y < 0
			|| y >= game_data->current_map_data.map_columns_number - 1)
			return (EXIT_FAILURE);
	if (duplicated_map[x][y] == '1' || duplicated_map[x][y] == 'V')
		return (EXIT_FAILURE);
	if (duplicated_map[x][y] == 'C')
	{
		duplicated_map[x][y] = '0';
		game_data->current_map_data.items_values.collectibles_number -= 1;
	}
	if (duplicated_map[x][y] == 'E')
	{
		duplicated_map[x][y] = '0';
		game_data->current_map_data.items_values.exit_number -= 1;
	}
	duplicated_map[x][y] = 'V';
	if ((game_data->current_map_data.items_values.exit_number == 0)
		&& (game_data->current_map_data.items_values.collectibles_number == 0))
		return (EXIT_SUCCESS);
	return (flood_fill_recursive_calls(game_data, duplicated_map, x, y));
}

t_map_status	launch_flood_fill(t_game_data game_data)
{
	char	**duplicated_map;
	int		character_coords[2];

	duplicated_map = duplicate_map_array(game_data);
	if (duplicated_map == NULL)
	{
		return (INVALID_MAP);
		//perror();
	}
	get_character_starting_position(duplicated_map, character_coords);
	if (flood_fill(&game_data, duplicated_map, character_coords[0],
			character_coords[1]) == EXIT_FAILURE)
	{
		ft_free_and_null(duplicated_map);
		return (INVALID_MAP);
	}
	if (game_data.current_map_data.items_values.collectibles_number != 0)
	{
		ft_free_and_null(duplicated_map);
		return (INVALID_MAP);
	}
	ft_free_and_null(duplicated_map);
	return (VALID_MAP);
}

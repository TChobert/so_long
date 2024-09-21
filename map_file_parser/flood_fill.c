/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 13:26:13 by tchobert          #+#    #+#             */
/*   Updated: 2024/09/21 20:52:02 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int flood_fill(t_game_data *game_data, char **duplicated_map, size_t x, size_t y)
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
		game_data->current_map_data.items_values.exit_number -= 1;
		duplicated_map[x][y] = '0';
	}
	duplicated_map[x][y] = 'V';

	if ((game_data->current_map_data.items_values.exit_number == 0)
		&& (game_data->current_map_data.items_values.collectibles_number == 0))
		return EXIT_SUCCESS;

	if (flood_fill(game_data, duplicated_map, x + 1, y) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	if (flood_fill(game_data, duplicated_map, x - 1, y) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	if (flood_fill(game_data, duplicated_map, x, y + 1) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	if (flood_fill(game_data, duplicated_map, x, y - 1) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);

	//duplicated_map[x][y] = '0';
	return (EXIT_FAILURE);
}

void	get_player_starting_position(char **map_array, size_t *player_coords)
{
	size_t	x;
	size_t	y;

	x = 0;
	while(map_array[x] != NULL)
	{
		y = 0;
		while (map_array[x][y] != '\0')
		{
			if (map_array[x][y] == 'P')
			{
				player_coords[0] = x;
				player_coords[1] = y;
				//printf("x = %zu, y = %zu\n", x, y);
				return ;
			}
			++y;
		}
		++x;
	}
	return ;
}

void	fill_new_array(t_game_data game_data, char **new_array)
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

size_t	get_map_array_size(char **map_array)
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

t_map_status	launch_flood_fill(t_game_data game_data)
{
	char	**duplicated_map;
	size_t	player_coords[2];

	duplicated_map = duplicate_map_array(game_data);
	display_array(duplicated_map);
	if (duplicated_map == NULL)
	{
		return (INVALID_MAP);
		//print_error !
	}
	get_player_starting_position(duplicated_map, player_coords);
	if (flood_fill(&game_data, duplicated_map, player_coords[0],
			player_coords[1]) == EXIT_FAILURE)
	{
		//printf("row %zu\n", game_data.current_map_data.map_rows_number);
		//printf("col %zu\n", game_data.current_map_data.map_columns_number);
		ft_free_and_null(duplicated_map);
		return (ft_putendl_fd("1", 2), INVALID_MAP);
	}
	if (game_data.current_map_data.items_values.collectibles_number != 0)
	{
		ft_free_and_null(duplicated_map);
		return (ft_putendl_fd("2", 2), INVALID_MAP);
	}
	ft_free_and_null(duplicated_map);
	return (VALID_MAP);
}

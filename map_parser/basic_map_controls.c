/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_map_controls.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 15:16:02 by tchobert          #+#    #+#             */
/*   Updated: 2024/09/19 19:49:01 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	add_line_data(const char *line, t_map_data *map_data)
// {
// 	map_data->items_values.collectibles_number = count_collectibles_items(line);
// 	map_data->items_values.player_number = count_player_items(line);
// 	map_data->items_values.exit_number = count_exit_items(line);
//}

t_map_status	map_array_lines_controls(char **map_array, t_map_data *map_data)
{
	size_t	i;

	i = 1;
	if (check_first_line(map_array[0], map_data) == INVALID_LINE)
		return (INVALID_MAP);
	while (i < map_data->map_lines_number - 1)
	{
		if (check_line(map_array[i], map_data) == INVALID_LINE)
		{
			return (INVALID_MAP);
		}
		++i;
	}
	if (check_last_line(map_array[map_data->map_lines_number - 1], map_data) == INVALID_LINE)
		return (INVALID_MAP);
	return (VALID_MAP);
	//checker map_data a la fin;
}

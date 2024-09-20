/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_array_lines_controls.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 15:16:02 by tchobert          #+#    #+#             */
/*   Updated: 2024/09/20 14:28:53 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map_status	check_map_items_values(t_map_data *map_data)
{
	if (map_data->items_values.collectibles_number < 1)
		return (INVALID_MAP);
	if (map_data->items_values.exit_number != 1)
		return (INVALID_MAP);
	if (map_data->items_values.player_number != 1)
		return (INVALID_MAP);
	return (VALID_MAP);
}


t_map_status	map_array_lines_controls(char **map_array, t_map_data *map_data)
{
	size_t	i;

	i = 1;
	if (check_first_line(map_array[0], map_data) == INVALID_LINE)
		return (INVALID_MAP);
	while (i < map_data->map_lines_number - 1)
	{
		if (check_line(map_array[i], map_data) == INVALID_LINE || check_line_items(map_array[i]) == INVALID_LINE)
		{
			return (INVALID_MAP);
		}
		++i;
	}
	if (check_last_line(map_array[map_data->map_lines_number - 1],
			map_data) == INVALID_LINE)
		return (INVALID_MAP);
	return (check_map_items_values(map_data));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_array_lines_controls.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 15:16:02 by tchobert          #+#    #+#             */
/*   Updated: 2024/09/23 16:35:56 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_map_status	check_map_items_values(t_game_data *game_data)
{
	if (game_data->current_map_data.items_values.collectibles_number < 1)
		return (INVALID_MAP);
	if (game_data->current_map_data.items_values.exit_number != 1)
		return (INVALID_MAP);
	if (game_data->current_map_data.items_values.player_number != 1)
		return (INVALID_MAP);
	return (VALID_MAP);
}


t_map_status	map_array_lines_controls(t_game_data *game_data)
{
	const size_t rows = game_data->current_map_data.map_rows_number;
	size_t	i;

	i = 1;
	if (check_first_line(game_data->current_map_data.map_array[0], game_data) == INVALID_LINE)
		return (INVALID_MAP);
	while (i < rows - 1)
	{
		if (check_line(game_data->current_map_data.map_array[i], game_data) == INVALID_LINE || check_line_items(game_data->current_map_data.map_array[i]) == INVALID_LINE)
		{
			return (INVALID_MAP);
		}
		++i;
	}
	if (check_last_line(game_data->current_map_data.map_array[i], game_data) == INVALID_LINE)
		return (INVALID_MAP);
	return (check_map_items_values(game_data));
}

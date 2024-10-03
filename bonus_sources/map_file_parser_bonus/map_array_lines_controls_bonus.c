/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_array_lines_controls_bonus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 15:16:02 by tchobert          #+#    #+#             */
/*   Updated: 2024/10/03 19:52:30 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static t_invalid_map_nature	is_double(int items_number)
{
	if (items_number > 1)
	{
		return (DOUBLE_ITEM);
	}
	return (NOT_CONFORM_MAP);
}

static t_map_status	check_map_items_values(t_game_data *game_data,
						t_invalid_map_nature *map_problem_status)
{
	if (game_data->map_data.items_values.collectibles_number < 1)
	{
		*map_problem_status = NOT_CONFORM_MAP;
		return (INVALID_MAP);
	}
	if (game_data->map_data.items_values.exit_number != 1)
	{
		*map_problem_status
			= is_double(game_data->map_data.items_values.exit_number);
		return (INVALID_MAP);
	}
	if (game_data->map_data.items_values.player_number != 1)
	{
		*map_problem_status
			= is_double(game_data->map_data.items_values.player_number);
		return (INVALID_MAP);
	}
	return (VALID_MAP);
}

static t_map_line_status	because_norminette(t_game_data *game_data,
								t_invalid_map_nature *map_problem_status)
{
	if (check_first_line(game_data->map_data.map_array[0], game_data)
		== INVALID_LINE)
	{
		*map_problem_status = NOT_CONFORM_MAP;
		return (INVALID_LINE);
	}
	return (VALID_LINE);
}

t_map_status	map_array_lines_controls(t_game_data *game_data,
					t_invalid_map_nature *map_problem_status)
{
	const size_t	rows = game_data->map_data.map_rows_number;
	size_t			i;

	i = 1;
	if (because_norminette(game_data, map_problem_status) == INVALID_LINE)
		return (INVALID_MAP);
	while (i < rows - 1)
	{
		if (check_line(game_data->map_data.map_array[i], game_data)
			== INVALID_LINE
			|| check_line_items(game_data->map_data.map_array[i])
			== INVALID_LINE)
		{
			*map_problem_status = NOT_CONFORM_MAP;
			return (INVALID_MAP);
		}
		++i;
	}
	if (check_last_line(game_data->map_data.map_array[i], game_data)
		== INVALID_LINE)
	{
		*map_problem_status = NOT_CONFORM_MAP;
		return (INVALID_MAP);
	}
	return (check_map_items_values(game_data, map_problem_status));
}

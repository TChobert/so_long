/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_line_checkers_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 18:00:19 by tchobert          #+#    #+#             */
/*   Updated: 2024/10/03 19:52:41 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_map_line_status	check_first_line(const char *first_line,
						t_game_data *game_data)
{
	if (first_line == NULL || is_full_wall(first_line) == false)
		return (INVALID_LINE);
	game_data->map_data.map_columns_number = get_line_size(first_line);
	return (VALID_LINE);
}

t_map_line_status	check_last_line(const char *last_line,
						t_game_data *game_data)
{
	if (last_line == NULL || is_full_wall(last_line) == false
		|| is_correct_size(last_line, game_data) == false)
		return (INVALID_LINE);
	return (VALID_LINE);
}

t_map_line_status	check_line(const char *line, t_game_data *game_data)
{
	if (line == NULL || is_correct_size(line, game_data) == false
		|| (is_surrounded_by_walls(line, game_data) == false))
	{
		return (INVALID_LINE);
	}
	add_line_data(line, game_data);
	return (VALID_LINE);
}

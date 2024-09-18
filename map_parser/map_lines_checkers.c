/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_lines_checkers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 18:00:19 by tchobert          #+#    #+#             */
/*   Updated: 2024/09/18 18:00:36 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map_line_status	check_last_line(const char *last_line, t_map_data *map_data)
{
	if (is_full_wall(last_line) == false || is_correct_size(last_line, map_data) == false)
		return (INVALID_LINE);
	map_data->map_lines_number += 1;
}

t_map_line_status	check_line(const char *line, t_map_data *map_data)
{
	if (is_surrounded_by_walls(line) == false || is_correct_size(line, map_data) == false)
		return (INVALID_LINE);
	add_line_data(line, map_data);
}
t_map_line_status	check_first_line(const char *first_line, t_map_data *map_data)
{
	if (first_line == NULL || is_full_wall(first_line) == false)
		return (INVALID_LINE);
	map_data->first_line_size = get_line_size(first_line);
	map_data->map_lines_number += 1;
	return (VALID_LINE);
}

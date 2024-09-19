/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_lines_checkers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 18:00:19 by tchobert          #+#    #+#             */
/*   Updated: 2024/09/19 19:44:15 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map_line_status	check_first_line(const char *first_line, t_map_data *map_data)
{
	if (first_line == NULL || is_full_wall(first_line) == false)
		return (INVALID_LINE);
	map_data->first_line_size = get_line_size(first_line);
	return (VALID_LINE);
}

t_map_line_status	check_last_line(const char *last_line, t_map_data *map_data)
{
	if (is_full_wall(last_line) == false || is_correct_size(last_line, map_data) == false)
		return (INVALID_LINE);
	return (VALID_LINE);
}

t_map_line_status	check_line(const char *line, t_map_data *map_data)
{
	if ((is_correct_size(line, map_data) == false) || (is_surrounded_by_walls(line, map_data) == false))
	{
		return (INVALID_LINE);
	}
	add_line_data(line, map_data);
	return (VALID_LINE);
}

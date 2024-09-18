/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_map_controls.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 15:16:02 by tchobert          #+#    #+#             */
/*   Updated: 2024/09/18 18:00:53 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	add_line_data(const char *line, t_map_data *map_data)
{
	map_data->items_values.collectibles_number = count_collectibles_items(line);
	map_data->items_values.player_number = count_player_items(line);
	map_data->items_values.exit_number = count_exit_items(line);
}

t_map_status	map_file_lines_controls(int map_fd, t_map_data *map_data)
{
	const char	*first_line = get_next_line(map_fd);
	if (check_first_line(first_line, map_data) == INVALID_LINE)
		return (INVALID_MAP);
	
	//checker map_data a la fin;
}

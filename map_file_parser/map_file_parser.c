/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:41:42 by tchobert          #+#    #+#             */
/*   Updated: 2024/09/20 17:15:00tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map_status	map_file_parser(const char *map_file_path,
									t_game_data *game_data)
{
	int			map_fd;

	if (check_map_file_type(map_file_path) == INVALID_FILE_TYPE)
		return (INVALID_MAP);
	if (open_map_file(map_file_path, &map_fd) == OPENING_ERROR)
	{
		close_and_free_routine(map_fd, game_data);
		return (INVALID_MAP);
	}
	game_data->current_map_data.map_array = build_map_array(map_fd, game_data);
	if (game_data->current_map_data.map_array == NULL)
	{
		close_and_free_routine(map_fd, game_data);
		return (EXIT_FAILURE);
	}
	if (map_array_lines_controls(game_data) == INVALID_MAP
			|| launch_flood_fill(*game_data) == INVALID_MAP)
	{
		close_and_free_routine(map_fd, game_data);
	 	return (INVALID_MAP);
	}
	//ft_free_and_null(game_data->current_map_data.map_array);
	close(map_fd);
	return (VALID_MAP);
}

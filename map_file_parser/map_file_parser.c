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

static t_map_status	map_controls(t_game_data *game_data, t_invalid_map_nature *map_problem_status)
{
	if (map_array_lines_controls(game_data) == INVALID_MAP)
	{
		*map_problem_status = NOT_CONFORM_MAP;
		return (INVALID_MAP);
	}
	if (launch_flood_fill(*game_data) == INVALID_MAP)
	{
		*map_problem_status = NO_PATH;
		return (INVALID_MAP);
	}
	if (map_size_control(game_data) == INVALID_MAP)
	{
		*map_problem_status = NOT_CONFORM_SIZE;
		return (INVALID_MAP);
	}
	return (VALID_MAP);
}

t_map_status	map_file_parser(const char *map_file_path,
									t_game_data *game_data)
{
	int						map_fd;
	t_invalid_map_nature	map_problem_status;

	map_problem_status = NO_PROBLEM;
	if (check_map_file_type(map_file_path) == INVALID_FILE_TYPE)
		return (INVALID_MAP);
	if (open_map_file(map_file_path, &map_fd) == OPENING_ERROR)
	{
		close_and_free_routine(map_fd, game_data);
		return (INVALID_MAP);
	}
	game_data->map_data.map_array = build_map_array(map_fd, game_data);
	if (game_data->map_data.map_array == NULL)
	{
		close_and_free_routine(map_fd, game_data);
		return (EXIT_FAILURE);
	}
	if (map_controls(game_data, &map_problem_status) == INVALID_MAP)
	{
		display_parsing_errors(map_problem_status);
		close_and_free_routine(map_fd, game_data);
		return (INVALID_MAP);
	}
	close(map_fd);
	return (VALID_MAP);
}

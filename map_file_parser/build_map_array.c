/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 17:55:08 by tchobert          #+#    #+#             */
/*   Updated: 2024/09/21 15:00:31 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*build_map_line(int map_file_fd, t_game_data *game_data)
{
	char	*map_line;
	char	*line;
	char	*temp_map_line;

	map_line = ft_strdup("");
	if (map_line == NULL)
		return (NULL);
	line = get_next_line(map_file_fd);
	while (line  != NULL)
	{
		temp_map_line = map_line;
		ft_asprintf(&map_line, "%s%s", map_line, line);
		free(line);
		line = get_next_line(map_file_fd);
		game_data->current_map_data.map_rows_number += 1;
		free(temp_map_line);
	}
	free(line);
	//test read
	return (map_line);
}

char	**build_map_array(int map_file_fd, t_game_data *game_data)
{
	char 	**map_array;
	char	*map_line;

	map_line = build_map_line(map_file_fd, game_data);
	if (map_line == NULL)
		return (NULL);
	map_array = ft_split(map_line, '\n');
	free(map_line);
	return (map_array);
}

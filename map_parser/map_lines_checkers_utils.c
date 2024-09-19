/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_lines_checkers_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 18:35:50 by tchobert          #+#    #+#             */
/*   Updated: 2024/09/19 19:42:55 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	get_line_size(const char *line)
{
	return (ft_strlen(line));
}

bool	is_full_wall(const char *line)
{
	size_t	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != WALL)
		{
			return (false);
		}
		++i;
	}
	return (true);
}

bool	is_correct_size(const char *line, t_map_data *map_data)
{
	const size_t	line_size = get_line_size(line);

	return (line_size == map_data->first_line_size);
}

bool	is_surrounded_by_walls(const char *line, t_map_data *map_data)
{
	return ((line[0] == WALL) && (line[map_data->first_line_size - 1] == WALL));
}

void	add_line_data(const char *line, t_map_data *map_data)
{
	map_data->items_values.collectibles_number = count_collectibles_items(line);
	map_data->items_values.player_number = count_player_items(line);
	map_data->items_values.exit_number = count_exit_items(line);
}

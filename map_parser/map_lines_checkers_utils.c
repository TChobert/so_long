/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_lines_checkers_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 18:35:50 by tchobert          #+#    #+#             */
/*   Updated: 2024/09/18 18:42:16 by tchobert         ###   ########.fr       */
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
			return (false);
		++i;
	}
	return (true);
}

bool	is_correct_size(const char *line, t_map_data *map_data)
{
	const size_t	line_size = get_line_size(line);

	return (line_size == map_data->first_line_size);
}

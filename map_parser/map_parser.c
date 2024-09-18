/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:41:42 by tchobert          #+#    #+#             */
/*   Updated: 2024/09/18 15:36:30 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_opening_status	open_map_file(const char *map_file_path, int *map_fd)
{
	if (check_map_file_type(map_file_path) == INVALID_FILE_TYPE)
	{
		ft_dprintf(STDERR_FILENO, "Error\nInvalid map file type. Please enter '%s' file\n", BER_SUFFIX);
		return (OPENING_ERROR);
	}
	*map_fd = open(map_file_path, O_RDONLY);
	if (*map_fd < 0)
	{
		display_opening_errors(map_file_path);
		return (OPENING_ERROR);
	}
	return (OPENING_SUCCESS);
}

t_map_status	map_parsing(const char *map_file_path)
{
	t_map_data	map_data;
	int	map_fd;

	if (open_map_file(map_file_path, &map_fd) == OPENING_ERROR)
	{
		if (map_fd > 0)
		{
			close(map_fd);
		}
		return (INVALID_MAP);
	}
	if (map_basic_controls(map_fd) == INVALID_MAP)
		return (INVALID_MAP);
	if (map_fd > 0)
		close(map_fd);
	return (VALID_MAP);
}

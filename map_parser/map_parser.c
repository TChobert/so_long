/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:41:42 by tchobert          #+#    #+#             */
/*   Updated: 2024/09/19 19:12:55 by tchobert         ###   ########.fr       */
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
char	*build_map_line(int map_file_fd, t_map_data *map_data)
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
		map_data->map_lines_number += 1;
		free(temp_map_line);
	}
	free(line);
	//test read
	return (map_line);
}

char	**build_map_array(int map_file_fd, t_map_data *map_data)
{
	char 	**map_array;
	char	*map_line;

	map_line = build_map_line(map_file_fd, map_data);
	if (map_line == NULL)
		return (NULL);
	map_array = ft_split(map_line, '\n');
	free(map_line);
	return (map_array);
}

t_map_status	map_parsing(const char *map_file_path)
{
	char		**map_array;
	t_map_data	map_data;
	int			map_fd;

	ft_bzero(&map_data, sizeof(map_data));
	if (open_map_file(map_file_path, &map_fd) == OPENING_ERROR)
	{
		if (map_fd < 0)
		{
			close(map_fd);
		}
		return (INVALID_MAP);
	}
	map_array = build_map_array(map_fd, &map_data);
	if (map_array == NULL)
		return (EXIT_FAILURE); //ERREUR A DEFINIR
	if (map_array_lines_controls(map_array, &map_data) == INVALID_MAP)
	{
		ft_free_and_null(map_array);
	 	return (INVALID_MAP);
	}
	//size_t	i = 0;
	// while (map_array[i] != NULL)
	// {
	// 	ft_putstr_fd(map_array[i], STDOUT_FILENO);
	// 	write(1, "\n", 1);
	// 	++i;
	// }
	ft_free_and_null(map_array);
	//printf("%zu\n", map_data.map_lines_number);
	close(map_fd);
	return (VALID_MAP);
}

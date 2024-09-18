/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:41:33 by tchobert          #+#    #+#             */
/*   Updated: 2024/09/18 15:08:38 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_opening_errors(const char *map_file_path)
{
	if (errno == EACCES)
		ft_dprintf(STDERR_FILENO, "Error\n%s: permission denied.\n", map_file_path);
	else if (errno == ENOENT)
		ft_dprintf(STDERR_FILENO, "Error\n%s : no such file found.\n", map_file_path);
	// else if (errno == EISDIR)
	// 	ft_dprintf(STDERR_FILENO, "Error\n%s : is a directory", map_file_path);
	else
		ft_dprintf(STDERR_FILENO, "Error\nopening error.\n");
}

t_opening_status	check_map_file_type(const char *map_file_path)
{
	const char		*file_suffix_position = map_file_path + (ft_strlen(map_file_path) - 4);

	if (ft_strcmp(file_suffix_position, BER_SUFFIX) != 0)
	{
		return (INVALID_FILE_TYPE);
	}
	return (VALID_FILE_TYPE);
}

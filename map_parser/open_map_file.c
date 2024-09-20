/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_map_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 17:38:14 by tchobert          #+#    #+#             */
/*   Updated: 2024/09/20 17:41:58 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_opening_status	open_map_file(const char *map_file_path, int *map_fd)
{
	*map_fd = open(map_file_path, O_RDONLY);
	if (*map_fd < 0)
	{
		display_opening_errors(map_file_path);
		return (OPENING_ERROR);
	}
	return (OPENING_SUCCESS);
}

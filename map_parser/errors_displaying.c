/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_displaying.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:53:51 by tchobert          #+#    #+#             */
/*   Updated: 2024/09/20 15:40:03 by tchobert         ###   ########.fr       */
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
	else
		ft_dprintf(STDERR_FILENO, "Error\nopening error.\n");
}

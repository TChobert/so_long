/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_displaying.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:53:51 by tchobert          #+#    #+#             */
/*   Updated: 2024/10/01 15:36:09 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_opening_errors(const char *map_file_path)
{
	if (errno == EACCES)
		ft_dprintf(STDERR_FILENO, "Error\n%s: permission denied.\n", map_file_path);
	else if (errno == ENOENT)
		ft_dprintf(STDERR_FILENO, "Error\n%s: no such file found.\n", map_file_path);
	// else if (errno == EISDIR)
	else
		ft_dprintf(STDERR_FILENO, "Error\n%s: opening error.\n", map_file_path);
}
void	display_parsing_errors(t_invalid_map_nature map_problem_status)
{
	if (map_problem_status == NOT_CONFORM_MAP)
		ft_dprintf(STDERR_FILENO, "Error\nYour map must contain at least one character, one collectible and one exit, and nothing else.\nIt must be rectangular and surrounded by walls.\n");
	else if (map_problem_status == NO_PATH)
		ft_dprintf(STDERR_FILENO, "Error\nThe character must have access to the exit and all collectibles.\n");
	else if (map_problem_status == NOT_CONFORM_SIZE)
		ft_dprintf(STDERR_FILENO, "Error\nYour map size is incorrect. The map must have dimensions of 50 by 28 tiles maximum.\n");
	else if (map_problem_status == DOUBLE_ITEM)
		ft_dprintf(STDERR_FILENO, "Error\nYour map must contain only one character and one exit.\n");
}

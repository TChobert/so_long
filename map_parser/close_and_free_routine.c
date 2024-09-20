/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_and_free_routine.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 17:28:47 by tchobert          #+#    #+#             */
/*   Updated: 2024/09/20 17:30:32 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	close_and_free_routine(int map_fd, char **map_array)
{
	if (map_fd > 0)
		close(map_fd);
	if (map_array != NULL)
		ft_free_and_null(map_array);
}

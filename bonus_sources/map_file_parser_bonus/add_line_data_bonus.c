/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_line_data_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:36:21 by tchobert          #+#    #+#             */
/*   Updated: 2024/10/03 19:51:46 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	add_line_data(const char *line, t_game_data *game_data)
{
	game_data->map_data.items_values.collectibles_number
		+= count_collectibles_items(line);
	game_data->map_data.items_values.player_number += count_player_items(line);
	game_data->map_data.items_values.exit_number += count_exit_items(line);
}

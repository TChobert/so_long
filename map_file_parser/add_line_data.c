/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_line_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:36:21 by tchobert          #+#    #+#             */
/*   Updated: 2024/09/26 16:34:21 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	add_line_data(const char *line, t_game_data *game_data)
{
	game_data->map_data.items_values.collectibles_number += count_collectibles_items(line);
	game_data->map_data.items_values.player_number += count_player_items(line);
	game_data->map_data.items_values.exit_number += count_exit_items(line);
}

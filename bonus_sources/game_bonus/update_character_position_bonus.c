/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_character_position_bonus.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 17:45:35 by tchobert          #+#    #+#             */
/*   Updated: 2024/10/03 19:50:54 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	display_current_moves_number(t_game_data *game_data)
{
	ft_printf("Moves: %d\n", game_data->character_data.moves_counter);
}

void	update_character_position(t_game_data *game_data,
										unsigned int *character_new_coords)
{
	game_data->character_data.character_coord[0] = character_new_coords[0];
	game_data->character_data.character_coord[1] = character_new_coords[1];
	game_data->character_data.moves_counter += 1;
	display_current_moves_number(game_data);
}

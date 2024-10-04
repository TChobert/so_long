/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_and_print_character_position_bonus.c        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:35:00 by tchobert          #+#    #+#             */
/*   Updated: 2024/10/04 16:33:19 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	update_and_print_character_position(t_game_data *game_data,
											unsigned int *character_new_coords)
{
	unsigned int	old_character_coords[2];

	old_character_coords[0] = game_data->character_data.character_coord[0];
	old_character_coords[1] = game_data->character_data.character_coord[1];
	update_character_position(game_data, character_new_coords);
	if (game_data->character_data.is_black_potion == true)
		print_bear_position(game_data, old_character_coords);
	else if (game_data->character_data.is_yellow_potion == true)
		print_crab_position(game_data, old_character_coords);
	else if (game_data->character_data.is_blue_potion == true)
		print_sanic_position(game_data, old_character_coords);
	else
		print_hedgehog_position(game_data, old_character_coords);
}

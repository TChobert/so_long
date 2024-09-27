/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_and_print_character_position.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:35:00 by tchobert          #+#    #+#             */
/*   Updated: 2024/09/27 14:45:37 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	update_character_position(t_game_data *game_data,
										unsigned int *character_new_coords)
{
	game_data->character_data.character_coord[0] = character_new_coords[0];
	game_data->character_data.character_coord[1] = character_new_coords[1];
	game_data->character_data.moves_counter+= 1;
}

static void	print_character_position(t_game_data *game_data,
										unsigned int *old_character_coords)
{
	draw_image(game_data, &game_data->images_data.floor_img,
				old_character_coords[0], old_character_coords[1]);
	draw_image(game_data, &game_data->images_data.character_img,
				game_data->character_data.character_coord[0],
				game_data->character_data.character_coord[1]);
}

void	update_and_print_character_position(t_game_data *game_data,
												unsigned int *character_new_coords)
{
	unsigned int	old_character_coords[2];

	old_character_coords[0] = game_data->character_data.character_coord[0];
	old_character_coords[1] = game_data->character_data.character_coord[1];
	update_character_position(game_data, character_new_coords);
	print_character_position(game_data, old_character_coords);
}

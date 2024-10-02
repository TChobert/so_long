/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:37:47 by tchobert          #+#    #+#             */
/*   Updated: 2024/10/02 13:40:56 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// static void	get_potion(t_game_data *game_data,
							//unsigned int *character_new_coords)
// {
// 	if (game_data->map_data.map_array[character_new_coords[0]]
			//[character_new_coords[1]] == RED_POTION_ITEM)
// 	{
// 		game_data->character_data.is_red_potion = true;
// 		game_data->map_data.map_array[character_new_coords[0]]
			//[character_new_coords[1]] = FLOOR_ITEM;
// 	}
// 	if (game_data->map_data.map_array[character_new_coords[0]]
			//[character_new_coords[1]] == GREEN_POTION_ITEM)
// 	{
// 		game_data->character_data.is_red_potion = false;
// 		game_data->map_data.map_array[character_new_coords[0]]
			//[character_new_coords[1]] = FLOOR_ITEM;
// 	}
// }

//get_potion(game_data, character_new_coords);

t_move_status	move_up(t_game_data *game_data)
{
	unsigned int	character_new_coords[2];

	character_new_coords[0] = game_data->character_data.character_coord[0] - 1;
	character_new_coords[1] = game_data->character_data.character_coord[1];
	if (check_move_status(game_data, character_new_coords) == INVALID_MOVE)
		return (INVALID_MOVE);
	get_collectible(game_data, character_new_coords);
	update_and_print_character_position(game_data, character_new_coords);
	return (VALID_MOVE);
}

t_move_status	move_left(t_game_data *game_data)
{
	unsigned int	character_new_coords[2];

	character_new_coords[0] = game_data->character_data.character_coord[0];
	character_new_coords[1] = game_data->character_data.character_coord[1] - 1;
	if (check_move_status(game_data, character_new_coords) == INVALID_MOVE)
		return (INVALID_MOVE);
	game_data->character_data.is_right = false;
	get_collectible(game_data, character_new_coords);
	update_and_print_character_position(game_data, character_new_coords);
	return (VALID_MOVE);
}

t_move_status	move_right(t_game_data *game_data)
{
	unsigned int	character_new_coords[2];

	character_new_coords[0] = game_data->character_data.character_coord[0];
	character_new_coords[1] = game_data->character_data.character_coord[1] + 1;
	if (check_move_status(game_data, character_new_coords) == INVALID_MOVE)
		return (INVALID_MOVE);
	game_data->character_data.is_right = true;
	get_collectible(game_data, character_new_coords);
	update_and_print_character_position(game_data, character_new_coords);
	return (VALID_MOVE);
}

t_move_status	move_down(t_game_data *game_data)
{
	unsigned int	character_new_coords[2];

	character_new_coords[0] = game_data->character_data.character_coord[0] + 1;
	character_new_coords[1] = game_data->character_data.character_coord[1];
	if (check_move_status(game_data, character_new_coords) == INVALID_MOVE)
		return (INVALID_MOVE);
	get_collectible(game_data, character_new_coords);
	update_and_print_character_position(game_data, character_new_coords);
	return (VALID_MOVE);
}

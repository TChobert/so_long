/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_checkers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:31:42 by tchobert          #+#    #+#             */
/*   Updated: 2024/09/30 19:30:47 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_move_status	check_exit_move(t_game_data *game_data, unsigned int *character_new_coords)
{
	if (game_data->map_data.map_array[character_new_coords[0]][character_new_coords[1]] == EXIT_ITEM && game_data->map_data.items_values.collectibles_number == 0)
	{
		game_data->character_data.moves_counter+= 1;
		game_data->map_data.items_values.exit_number -= 1;
		close_game(game_data);
	}
	else if (game_data->map_data.map_array[character_new_coords[0]][character_new_coords[1]] == EXIT_ITEM && game_data->map_data.items_values.collectibles_number != 0)
		game_data->character_data.is_on_exit = true;
	else if (game_data->character_data.is_on_exit == true &&
		game_data->map_data.map_array[character_new_coords[0]][character_new_coords[1]] != EXIT_ITEM)
	{
		game_data->character_data.is_on_exit = false;
	}
	return (VALID_MOVE);
}
t_move_status	check_move_status(t_game_data *game_data, unsigned int *character_new_coords)
{
	if (game_data->map_data.map_array[character_new_coords[0]][character_new_coords[1]] == WALL_ITEM)
		return (INVALID_MOVE);
	return (check_exit_move(game_data, character_new_coords));
}

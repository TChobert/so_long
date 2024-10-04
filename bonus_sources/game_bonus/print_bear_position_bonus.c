/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bear_position_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 16:30:45 by tchobert          #+#    #+#             */
/*   Updated: 2024/10/04 16:31:50 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	print_bear_on_exit(t_game_data *game_data,
										unsigned int *old_character_coords)
{
	if (game_data->character_data.is_right == true)
	{
		draw_image(game_data, &game_data->images_data.bear_exit_right_img,
			game_data->character_data.character_coord[0],
			game_data->character_data.character_coord[1]);
	}
	else
	{
		draw_image(game_data, &game_data->images_data.bear_exit_left_img,
			game_data->character_data.character_coord[0],
			game_data->character_data.character_coord[1]);
	}
	draw_image(game_data, &game_data->images_data.floor_img,
		old_character_coords[0], old_character_coords[1]);
}

void	print_bear_position(t_game_data *game_data,
										unsigned int *old_character_coords)
{
	if (game_data->character_data.is_on_exit == true)
		print_bear_on_exit(game_data, old_character_coords);
	else
	{
		if (game_data->map_data.map_array[old_character_coords[0]]
			[old_character_coords[1]] == EXIT_ITEM)
			draw_image(game_data, &game_data->images_data.exit_img,
				old_character_coords[0], old_character_coords[1]);
		else
		{
			draw_image(game_data, &game_data->images_data.floor_img,
				old_character_coords[0], old_character_coords[1]);
		}
		if (game_data->character_data.is_right == true)
			draw_image(game_data, &game_data->images_data.bear_right_img,
				game_data->character_data.character_coord[0],
				game_data->character_data.character_coord[1]);
		else
			draw_image(game_data, &game_data->images_data.bear_left_img,
				game_data->character_data.character_coord[0],
				game_data->character_data.character_coord[1]);
	}
}

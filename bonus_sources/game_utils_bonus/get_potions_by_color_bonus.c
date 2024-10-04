/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_potions_by_color_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 17:37:07 by tchobert          #+#    #+#             */
/*   Updated: 2024/10/04 17:41:24 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	get_blue_potion(t_game_data *game_data,
								unsigned int *character_new_coords)
{
	if (game_data->map_data.map_array[character_new_coords[0]]
		[character_new_coords[1]] == BLUE_POTION_ITEM)
	{
		game_data->character_data.is_black_potion = false;
		game_data->character_data.is_yellow_potion = false;
		game_data->character_data.is_blue_potion = true;
		printf("Blue potion\n");
		game_data->map_data.map_array[character_new_coords[0]]
		[character_new_coords[1]] = FLOOR_ITEM;
	}
}

void	get_red_potion(t_game_data *game_data,
								unsigned int *character_new_coords)
{
	if (game_data->map_data.map_array[character_new_coords[0]]
		[character_new_coords[1]] == RED_POTION_ITEM)
	{
		game_data->character_data.is_red_potion = true;
		game_data->map_data.map_array[character_new_coords[0]]
		[character_new_coords[1]] = FLOOR_ITEM;
	}
}

void	get_green_potion(t_game_data *game_data,
							unsigned int *character_new_coords)
{
	if (game_data->map_data.map_array[character_new_coords[0]]
		[character_new_coords[1]] == GREEN_POTION_ITEM)
	{
		game_data->character_data.is_red_potion = false;
		game_data->character_data.is_black_potion = false;
		game_data->character_data.is_yellow_potion = false;
		game_data->character_data.is_blue_potion = false;
		game_data->map_data.map_array[character_new_coords[0]]
		[character_new_coords[1]] = FLOOR_ITEM;
	}
}

void	get_black_potion(t_game_data *game_data,
								unsigned int *character_new_coords)

{
	if (game_data->map_data.map_array[character_new_coords[0]]
		[character_new_coords[1]] == BLACK_POTION_ITEM)
	{
		game_data->character_data.is_black_potion = true;
		game_data->character_data.is_blue_potion = false;
		game_data->character_data.is_yellow_potion = false;
		game_data->map_data.map_array[character_new_coords[0]]
		[character_new_coords[1]] = FLOOR_ITEM;
	}
}

void	get_yellow_potion(t_game_data *game_data,
								unsigned int *character_new_coords)
{
	if (game_data->map_data.map_array[character_new_coords[0]]
		[character_new_coords[1]] == YELLOW_POTION_ITEM)
	{
		game_data->character_data.is_black_potion = false;
		game_data->character_data.is_blue_potion = false;
		game_data->character_data.is_yellow_potion = true;
		game_data->map_data.map_array[character_new_coords[0]]
		[character_new_coords[1]] = FLOOR_ITEM;
	}
}

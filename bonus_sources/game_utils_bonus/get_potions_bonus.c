/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_potions_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 13:10:30 by tchobert          #+#    #+#             */
/*   Updated: 2024/10/04 14:29:58 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	get_blue_potion(t_game_data *game_data,
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

static void get_red_potion(t_game_data *game_data,
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

static void	get_green_potion(t_game_data *game_data,
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

static void	get_black_potion(t_game_data *game_data,
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

static void	get_yellow_potion(t_game_data *game_data,
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

void	get_potions(t_game_data *game_data,
						unsigned int *character_new_coords)
{
	get_red_potion(game_data, character_new_coords);
	get_green_potion(game_data, character_new_coords);
	get_black_potion(game_data, character_new_coords);
	get_yellow_potion(game_data, character_new_coords);
	get_blue_potion(game_data, character_new_coords);
}

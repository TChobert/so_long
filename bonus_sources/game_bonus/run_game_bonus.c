/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_game_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:10:09 by tchobert          #+#    #+#             */
/*   Updated: 2024/10/03 19:50:39 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	init_map_items(t_game_data *game_data, t_map_item *map_items)
{
	map_items[0] = (t_map_item)
	{FLOOR_ITEM, &game_data->images_data.floor_img};
	map_items[1] = (t_map_item)
	{WALL_ITEM, &game_data->images_data.wall_img};
	map_items[2] = (t_map_item)
	{PLAYER_ITEM, &game_data->images_data.hedgehog_left_img};
	map_items[3] = (t_map_item)
	{COLLECTIBLE_ITEM, &game_data->images_data.collectible_img};
	map_items[4] = (t_map_item)
	{EXIT_ITEM, &game_data->images_data.exit_img};
	map_items[5] = (t_map_item)
	{RED_POTION_ITEM, &game_data->images_data.red_potion_img};
	map_items[6] = (t_map_item)
	{GREEN_POTION_ITEM, &game_data->images_data.green_potion_img};
	map_items[7] = (t_map_item)
	{BLACK_POTION_ITEM, &game_data->images_data.black_potion_img};
	map_items[8] = (t_map_item){0, NULL};
}

static int	define_keycode_to_move_function(int keycode)
{
	int	key_function_call;

	key_function_call = -1;
	if (keycode == W_KEY)
		key_function_call = KEY_W_INDEX;
	else if (keycode == A_KEY)
		key_function_call = KEY_A_INDEX;
	else if (keycode == S_KEY)
		key_function_call = KEY_S_INDEX;
	else if (keycode == D_KEY)
		key_function_call = KEY_D_INDEX;
	else if (keycode == ESC_KEY)
		key_function_call = KEY_ESC_INDEX;
	return (key_function_call);
}

static int	reverse_define_keycode_to_move_function(int keycode)
{
	int	key_function_call;

	key_function_call = -1;
	if (keycode == W_KEY)
		key_function_call = KEY_D_INDEX;
	else if (keycode == A_KEY)
		key_function_call = KEY_S_INDEX;
	else if (keycode == S_KEY)
		key_function_call = KEY_A_INDEX;
	else if (keycode == D_KEY)
		key_function_call = KEY_W_INDEX;
	else if (keycode == ESC_KEY)
		key_function_call = KEY_ESC_INDEX;
	return (key_function_call);
}

static int	handle_keypress(int keycode, t_game_data *game_data)
{
	const t_key_press_functions	key_press_functions[] = {
		move_up,
		move_left,
		move_right,
		move_down,
		close_game
	};
	int							key_function_call;

	if (game_data->character_data.is_red_potion == true)
	{
		key_function_call = reverse_define_keycode_to_move_function(keycode);
	}
	else
	key_function_call = define_keycode_to_move_function(keycode);
	if (key_function_call >= 0 && key_function_call < 5)
	{
		key_press_functions[key_function_call](game_data);
	}
	return (EXIT_SUCCESS);
}

int	run_game(t_game_data *game_data)
{
	t_map_item	map_items[9];

	init_map_items(game_data, map_items);
	place_potions_randomly(game_data, 1, 1, 1);
	if (draw_map_to_window(game_data, map_items) == EXIT_FAILURE)
	{
		close_game(game_data);
		return (EXIT_FAILURE);
	}
	mlx_key_hook(game_data->mlx_data.win_ptr, handle_keypress, game_data);
	mlx_hook(game_data->mlx_data.win_ptr, DestroyNotify, NoEventMask,
		cross_click, game_data);
	mlx_loop(game_data->mlx_data.mlx_ptr);
	return (EXIT_SUCCESS);
}

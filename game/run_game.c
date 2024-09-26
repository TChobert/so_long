/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:10:09 by tchobert          #+#    #+#             */
/*   Updated: 2024/09/26 16:18:37 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void init_map_items(t_game_data *game_data, t_map_item *map_items)
{
	map_items[0] = (t_map_item){FLOOR_ITEM, &game_data->images_data.floor_img};
	map_items[1] = (t_map_item){WALL_ITEM, &game_data->images_data.wall_img};
	map_items[2] = (t_map_item){PLAYER_ITEM, &game_data->images_data.character_img};
	map_items[3] = (t_map_item){COLLECTIBLE_ITEM, &game_data->images_data.collectible_img};
	map_items[4] = (t_map_item){EXIT_ITEM, &game_data->images_data.exit_img};
	map_items[5] = (t_map_item){0, NULL};
}

void	update_character_position(t_game_data *game_data, unsigned int *character_new_coords)
{
	game_data->current_character_data.character_coord[0] = character_new_coords[0];
	game_data->current_character_data.character_coord[1] = character_new_coords[1];
}

void	update_and_print_character_position(t_game_data *game_data, unsigned int *character_new_coords)
{
	unsigned int	old_character_coords[2];

	old_character_coords[0] = game_data->current_character_data.character_coord[0];
	old_character_coords[1] = game_data->current_character_data.character_coord[1];
	update_character_position(game_data, character_new_coords);
	draw_image(game_data, &game_data->images_data.floor_img, old_character_coords[0], old_character_coords[1]);
	draw_image(game_data, &game_data->images_data.character_img, character_new_coords[0], character_new_coords[1]);
}

t_move_status	move_up(t_game_data *game_data)
{
	unsigned int	character_new_coords[2];

	character_new_coords[0] = game_data->current_character_data.character_coord[0];
	character_new_coords[1] = game_data->current_character_data.character_coord[1] - 1;
	if (check_move_status(game_data, character_new_coords) == INVALID_MOVE)
		return (INVALID_MOVE);
	update_and_print_character_position(game_data, character_new_coords);
	return (VALID_MOVE);
}

t_move_status	move_left(t_game_data *game_data)
{
	unsigned int	character_new_coords[2];

	character_new_coords[0] = game_data->current_character_data.character_coord[0] - 1;
	character_new_coords[1] = game_data->current_character_data.character_coord[1];
	if (check_move_status(game_data, character_new_coords) == INVALID_MOVE)
		return (INVALID_MOVE);
	update_and_print_character_position(game_data, character_new_coords);
	return (VALID_MOVE);
}

t_move_status	move_right(t_game_data *game_data)
{
	unsigned int	character_new_coords[2];

	character_new_coords[0] = game_data->current_character_data.character_coord[0] + 1;
	character_new_coords[1] = game_data->current_character_data.character_coord[1];
	if (check_move_status(game_data, character_new_coords) == INVALID_MOVE)
		return (INVALID_MOVE);
	update_and_print_character_position(game_data, character_new_coords);
	return (VALID_MOVE);
}

t_move_status	move_down(t_game_data *game_data)
{
	unsigned int	character_new_coords[2];

	character_new_coords[0] = game_data->current_character_data.character_coord[0];
	character_new_coords[1] = game_data->current_character_data.character_coord[1] + 1;
	if (check_move_status(game_data, character_new_coords) == INVALID_MOVE)
		return (INVALID_MOVE);
	update_and_print_character_position(game_data, character_new_coords);
	return (VALID_MOVE);
}

int	close_game(t_game_data *game_data)
{
	mlx_destroy_window(game_data->mlx_data.mlx_ptr, game_data->mlx_data.win_ptr);
	exit(EXIT_SUCCESS);
}

void	handle_keypress(int keycode, t_game_data *game_data)
{
	key_press_functions	key_press_functions[] = {
		move_up,
		move_left,
		move_right,
		move_down,
		close_game
	};

	return (key_press_functions[keycode](game_data));
}

int	run_game(t_game_data *game_data)
{
	t_map_item	map_items[6];

	init_map_items(game_data, map_items);
	if (draw_map_to_window(game_data, map_items) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	mlx_key_hook(game_data->mlx_data.win_ptr, handle_keypress, game_data);
	mlx_loop(game_data->mlx_data.mlx_ptr);
	return (EXIT_SUCCESS);
}




























// (void)game_data;
	// mlx_ptr = mlx_init();
	// if (mlx_ptr == NULL)
	// 	return (EXIT_FAILURE);
	// win_ptr = mlx_new_window(mlx_ptr, game_data->current_map_data.map_columns_number * TILE_SIZE, game_data->current_map_data.map_rows_number * TILE_SIZE, "Test");
	// img_ptr = mlx_xpm_file_to_image(mlx_ptr, "./assets/Untitled.xpm",
	// 		&img_width, &img_height);
	//get_character_starting_position(game_data->current_map_data.map_array, game_data->current_character_data.character_starting_coord);
	//mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, pixel_x, pixel_y);
	// if (img_ptr == NULL)
	// {
	// 	mlx_destroy_display(mlx_ptr);
	// 	return (EXIT_FAILURE);
	// }
	// if (win_ptr == NULL)
	// {
	// 	mlx_destroy_display(mlx_ptr);
	// 	return (EXIT_FAILURE);
	// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_and_print_character_position_bonus.c        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:35:00 by tchobert          #+#    #+#             */
/*   Updated: 2024/10/04 16:20:33 by tchobert         ###   ########.fr       */
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

static void	print_hedgehog_on_exit(t_game_data *game_data,
										unsigned int *old_character_coords)
{
	if (game_data->character_data.is_right == true)
	{
		draw_image(game_data, &game_data->images_data.hedgehog_exit_right_img,
			game_data->character_data.character_coord[0],
			game_data->character_data.character_coord[1]);
	}
	else
	{
		draw_image(game_data, &game_data->images_data.hedgehog_exit_left_img,
			game_data->character_data.character_coord[0],
			game_data->character_data.character_coord[1]);
	}
	draw_image(game_data, &game_data->images_data.floor_img,
		old_character_coords[0], old_character_coords[1]);
}

static void	print_bear_position(t_game_data *game_data,
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

void	print_sanic_on_exit(t_game_data *game_data,
								unsigned int *old_character_coords)
{
	if (game_data->character_data.is_right == true)
	{
		draw_image(game_data, &game_data->images_data.sanic_exit_right_img,
			game_data->character_data.character_coord[0],
			game_data->character_data.character_coord[1]);
	}
	else
	{
		draw_image(game_data, &game_data->images_data.sanic_exit_left_img,
			game_data->character_data.character_coord[0],
			game_data->character_data.character_coord[1]);
	}
	draw_image(game_data, &game_data->images_data.floor_img,
		old_character_coords[0], old_character_coords[1]);
}

static void print_sanic_position(t_game_data *game_data,
									unsigned int *old_character_coords)
{
	if (game_data->character_data.is_on_exit == true)
		print_sanic_on_exit(game_data, old_character_coords);
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
		{
			draw_image(game_data, &game_data->images_data.sanic_right_img,
				game_data->character_data.character_coord[0],
				game_data->character_data.character_coord[1]);
		}
		else
			draw_image(game_data, &game_data->images_data.sanic_left_img,
				game_data->character_data.character_coord[0],
				game_data->character_data.character_coord[1]);
	}
}

static void	print_hedgehog_position(t_game_data *game_data,
										unsigned int *old_character_coords)
{
	if (game_data->character_data.is_on_exit == true)
		print_hedgehog_on_exit(game_data, old_character_coords);
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
			draw_image(game_data, &game_data->images_data.hedgehog_right_img,
				game_data->character_data.character_coord[0],
				game_data->character_data.character_coord[1]);
		else
			draw_image(game_data, &game_data->images_data.hedgehog_left_img,
				game_data->character_data.character_coord[0],
				game_data->character_data.character_coord[1]);
	}
}

static void	print_crab_on_exit(t_game_data *game_data,
									unsigned int *old_character_coords)
{
	draw_image(game_data, &game_data->images_data.crab_exit_img,
			game_data->character_data.character_coord[0],
			game_data->character_data.character_coord[1]);
	draw_image(game_data, &game_data->images_data.floor_img,
		old_character_coords[0], old_character_coords[1]);
}

static void	print_crab_position(t_game_data *game_data,
									unsigned int *old_character_coords)
{
	if (game_data->character_data.is_on_exit == true) {
		print_crab_on_exit(game_data, old_character_coords);
	}
	else
		draw_image(game_data, &game_data->images_data.crab_img,
			game_data->character_data.character_coord[0],
			game_data->character_data.character_coord[1]);
	if (game_data->map_data.map_array[old_character_coords[0]]
		[old_character_coords[1]] == EXIT_ITEM) {
		draw_image(game_data, &game_data->images_data.exit_img,
			old_character_coords[0], old_character_coords[1]);
	}
	else
	{
		draw_image(game_data, &game_data->images_data.floor_img,
			old_character_coords[0], old_character_coords[1]);
	}
}

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

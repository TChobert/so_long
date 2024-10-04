/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_game_images_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 16:35:24 by tchobert          #+#    #+#             */
/*   Updated: 2024/10/04 16:54:28 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	load_hedgehog_images(t_game_data *game_data)
{
	if (load_image(game_data, &game_data->images_data.hedgehog_left_img,
			"bonus_sources/assets_bonus/character_left.xpm") == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (load_image(game_data, &game_data->images_data.hedgehog_right_img,
			"./bonus_sources/assets_bonus/character_right.xpm") == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (load_image(game_data, &game_data->images_data.hedgehog_exit_right_img,
			"./bonus_sources/assets_bonus/exit_stairs_right.xpm")
		== EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (load_image(game_data, &game_data->images_data.hedgehog_exit_left_img,
			"./bonus_sources/assets_bonus/exit_stairs_with_character.xpm")
		== EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	load_bear_and_crab_images(t_game_data *game_data)
{
	if (load_image(game_data, &game_data->images_data.bear_right_img,
			"./bonus_sources/assets_bonus/bear_RIGHT.xpm") == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (load_image(game_data, &game_data->images_data.bear_left_img,
			"./bonus_sources/assets_bonus/bear_right.xpm.xpm") == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (load_image(game_data, &game_data->images_data.bear_exit_right_img,
			"./bonus_sources/assets_bonus/bear_exit_right.xpm") == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (load_image(game_data, &game_data->images_data.bear_exit_left_img,
			"./bonus_sources/assets_bonus/exit_bear_left.xpm") == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (load_image(game_data, &game_data->images_data.crab_img,
			"./bonus_sources/assets_bonus/crab.xpm") == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (load_image(game_data, &game_data->images_data.crab_exit_img,
			"./bonus_sources/assets_bonus/crab_exit.xpm") == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	load_sanic_images(t_game_data *game_data)
{
	if (load_image(game_data, &game_data->images_data.sanic_right_img,
			"./bonus_sources/assets_bonus/sanic_right.xpm") == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (load_image(game_data, &game_data->images_data.sanic_left_img,
			"./bonus_sources/assets_bonus/sanic_left.xpm") == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (load_image(game_data, &game_data->images_data.sanic_exit_right_img,
			"./bonus_sources/assets_bonus/Sanic_exit_right.xpm")
		== EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (load_image(game_data, &game_data->images_data.sanic_exit_left_img,
			"./bonus_sources/assets_bonus/sanic_exit_left.xpm") == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	load_potions_images(t_game_data *game_data)
{
	if (load_image(game_data, &game_data->images_data.red_potion_img,
			"./bonus_sources/assets_bonus/red_potion.xpm") == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (load_image(game_data, &game_data->images_data.green_potion_img,
			"./bonus_sources/assets_bonus/green_potion.xpm") == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (load_image(game_data, &game_data->images_data.black_potion_img,
			"./bonus_sources/assets_bonus/black_potion.xpm") == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (load_image(game_data, &game_data->images_data.yellow_potion_img,
			"./bonus_sources/assets_bonus/yellow_potion.xpm") == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (load_image(game_data, &game_data->images_data.blue_potion_img,
			"./bonus_sources/assets_bonus/blue_potion.xpm") == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	load_items_images(t_game_data *game_data)
{
	if (load_image(game_data, &game_data->images_data.collectible_img,
			"./bonus_sources/assets_bonus/exp_book.xpm") == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (load_image(game_data, &game_data->images_data.exit_img,
			"./bonus_sources/assets_bonus/exit_stairs.xpm") == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (load_image(game_data, &game_data->images_data.wall_img,
			"./bonus_sources/assets_bonus/bookshelf_resized.xpm")
		== EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (load_image(game_data, &game_data->images_data.floor_img,
			"./bonus_sources/assets_bonus/test_wood2.xpm") == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	load_game_images(t_game_data *game_data)
{
	if (load_hedgehog_images(game_data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (load_bear_and_crab_images(game_data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (load_sanic_images(game_data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (load_items_images(game_data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (load_potions_images(game_data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	game_data->images_data.is_images_loaded = true;
	return (EXIT_SUCCESS);
}

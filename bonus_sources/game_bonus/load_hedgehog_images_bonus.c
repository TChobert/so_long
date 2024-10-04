/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_hedgehog_images_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 17:29:59 by tchobert          #+#    #+#             */
/*   Updated: 2024/10/04 17:31:02 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	load_hedgehog_images(t_game_data *game_data)
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

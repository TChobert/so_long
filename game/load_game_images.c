/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_game_images.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 16:35:24 by tchobert          #+#    #+#             */
/*   Updated: 2024/10/02 16:45:31 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_image_load(t_game_data *game_data, t_image_data *image_data,
				const char *file_path)
{
	if (image_data->img_ptr == NULL)
	{
		ft_dprintf(STDERR_FILENO, "Error\nFailed to load image: %s.\n",
			file_path);
		game_data->images_data.is_images_loaded = false;
		close_game(game_data);
	}
	return (EXIT_SUCCESS);
}

static int	load_image(t_game_data *game_data, t_image_data *image_data,
				const char *file_path)
{
	image_data->img_ptr = mlx_xpm_file_to_image(game_data->mlx_data.mlx_ptr,
			(char *)file_path, &image_data->width, &image_data->height);
	return (check_image_load(game_data, image_data, file_path));
}

static int	load_character_images(t_game_data *game_data)
{
	if (load_image(game_data, &game_data->images_data.character_img,
			"./assets/character_left.xpm") == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (load_image(game_data, &game_data->images_data.character_right_img,
			"./assets/character_right.xpm") == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (load_image(game_data, &game_data->images_data.character_exit_right_img,
			"./assets/exit_stairs_right.xpm") == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (load_image(game_data, &game_data->images_data.character_exit_left_img,
			"./assets/exit_stairs_with_character.xpm") == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	load_items_images(t_game_data *game_data)
{
	if (load_image(game_data, &game_data->images_data.collectible_img,
			"./assets/exp_book.xpm") == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (load_image(game_data, &game_data->images_data.exit_img,
			"./assets/exit_stairs.xpm") == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (load_image(game_data, &game_data->images_data.wall_img,
			"./assets/bookshelf_resized.xpm") == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (load_image(game_data, &game_data->images_data.floor_img,
			"./assets/test_wood2.xpm") == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	load_game_images(t_game_data *game_data)
{
	if (load_character_images(game_data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (load_items_images(game_data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	game_data->images_data.is_images_loaded = true;
	return (EXIT_SUCCESS);
}

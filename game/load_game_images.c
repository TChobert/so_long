/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_game_images.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 16:35:24 by tchobert          #+#    #+#             */
/*   Updated: 2024/09/30 19:09:39 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int check_image_load(void *mlx_ptr, t_image_data *image_data)
{
	if (image_data->img_ptr == NULL)
	{
		mlx_destroy_display(mlx_ptr); // DANS ROUTINE EXIT OU STAY HERE ??
		exit(EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int load_image(void *mlx_ptr, t_image_data *image_data, const char *file_path)
{
	image_data->img_ptr = mlx_xpm_file_to_image(mlx_ptr, (char *)file_path, &image_data->width, &image_data->height);
	return (check_image_load(mlx_ptr, image_data));
}

static int	load_character_images(t_game_data *game_data)
{
	if (load_image(game_data->mlx_data.mlx_ptr, &game_data->images_data.character_img, "./assets/character_left.xpm") == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (load_image(game_data->mlx_data.mlx_ptr, &game_data->images_data.character_right_img, "./assets/character_right.xpm") == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (load_image(game_data->mlx_data.mlx_ptr, &game_data->images_data.character_on_exit_right_img, "./assets/exit_stairs_right.xpm") == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (load_image(game_data->mlx_data.mlx_ptr, &game_data->images_data.character_on_exit_left_img, "./assets/exit_stairs_with_character.xpm") == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	load_game_images(t_game_data *game_data)
{
	if (load_character_images(game_data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (load_image(game_data->mlx_data.mlx_ptr, &game_data->images_data.collectible_img, "./assets/exp_book.xpm") == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (load_image(game_data->mlx_data.mlx_ptr, &game_data->images_data.exit_img, "./assets/exit_stairs.xpm") == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (load_image(game_data->mlx_data.mlx_ptr, &game_data->images_data.wall_img, "./assets/bookshelf_resized.xpm") == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (load_image(game_data->mlx_data.mlx_ptr, &game_data->images_data.floor_img, "./assets/test_wood2.xpm") == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (load_image(game_data->mlx_data.mlx_ptr, &game_data->images_data.red_potion_img, "./assets/red_potion.xpm") == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (load_image(game_data->mlx_data.mlx_ptr, &game_data->images_data.green_potion_img, "./assets/green_potion.xpm") == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

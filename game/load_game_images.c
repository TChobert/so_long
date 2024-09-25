/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_game_images.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 16:35:24 by tchobert          #+#    #+#             */
/*   Updated: 2024/09/25 19:24:14 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int check_image_load(void *mlx_ptr, t_image_data *image_data)
{
	if (image_data->img_ptr == NULL)
	{
		mlx_destroy_display(mlx_ptr);
		exit(EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int load_image(void *mlx_ptr, t_image_data *image_data, const char *file_path)
{
	image_data->img_ptr = mlx_xpm_file_to_image(mlx_ptr, (char *)file_path, &image_data->width, &image_data->height);
	return (check_image_load(mlx_ptr, image_data));
}

int	load_game_images(t_game_data *game_data)
{
	if (load_image(game_data->mlx_data.mlx_ptr, &game_data->images_data.character_img, "./assets/test_perso.xpm") == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (load_image(game_data->mlx_data.mlx_ptr, &game_data->images_data.collectible_img, "./assets/collectible_test.xpm") == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (load_image(game_data->mlx_data.mlx_ptr, &game_data->images_data.exit_img, "./assets/exit_test.xpm") == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (load_image(game_data->mlx_data.mlx_ptr, &game_data->images_data.wall_img, "./assets/mur_test.xpm") == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (load_image(game_data->mlx_data.mlx_ptr, &game_data->images_data.floor_img, "./assets/sol_test.xpm") == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

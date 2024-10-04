/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_image_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 12:57:27 by tchobert          #+#    #+#             */
/*   Updated: 2024/10/04 12:58:12 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

int	load_image(t_game_data *game_data, t_image_data *image_data,
				const char *file_path)
{
	image_data->img_ptr = mlx_xpm_file_to_image(game_data->mlx_data.mlx_ptr,
			(char *)file_path, &image_data->width, &image_data->height);
	return (check_image_load(game_data, image_data, file_path));
}

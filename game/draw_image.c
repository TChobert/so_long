/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 16:31:04 by tchobert          #+#    #+#             */
/*   Updated: 2024/09/26 16:32:06 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	draw_image(t_game_data *game_data, t_image_data *image_data,
				size_t x, size_t y)
{
	if (game_data == NULL || game_data->mlx_data.mlx_ptr == NULL
			|| game_data->mlx_data.win_ptr == NULL
			|| game_data->images_data.floor_img.img_ptr == NULL)
	{
		return (EXIT_FAILURE);
	}
	mlx_put_image_to_window(game_data->mlx_data.mlx_ptr,
								game_data->mlx_data.win_ptr,
								image_data->img_ptr,
								y * TILE_SIZE, x * TILE_SIZE);
	return (EXIT_SUCCESS);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_to_window.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:39:28 by tchobert          #+#    #+#             */
/*   Updated: 2024/09/26 14:40:21 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	draw_image(t_game_data *game_data, t_image_data *image_data,
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

int	draw_map_to_window(t_game_data	*game_data, t_map_item *map_items)
{
	size_t	x;
	size_t	y;
	size_t	i;

	x = 0;
	while (x < game_data->current_map_data.map_rows_number)
	{
		y = 0;
		while (y < game_data->current_map_data.map_columns_number)
		{
			i = 0;
			while (map_items[i].item != 0)
			{
				if (game_data->current_map_data.map_array[x][y]
						== map_items[i].item)
				{
					if (draw_image(game_data, map_items[i].image_data, x, y) == EXIT_FAILURE)
						return (EXIT_FAILURE);
				}
				++i;
			}
			++y;
		}
		++x;
	}
	return (EXIT_SUCCESS);
}

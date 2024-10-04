/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_to_window_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:39:28 by tchobert          #+#    #+#             */
/*   Updated: 2024/10/04 18:01:51 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	get_and_draw_image(t_game_data *game_data, t_map_item *map_items,
				size_t x, size_t y)
{
	size_t	i;

	i = 0;
	while (map_items[i].item != 0)
	{
		if (game_data->map_data.map_array[x][y]
						== map_items[i].item)
		{
			if (draw_image(game_data, map_items[i].image_data, x, y)
				== EXIT_FAILURE)
			{
				return (EXIT_FAILURE);
			}
		}
		++i;
	}
	return (EXIT_SUCCESS);
}

int	draw_map_to_window(t_game_data	*game_data, t_map_item *map_items)
{
	size_t	x;
	size_t	y;

	x = 0;
	while (x < game_data->map_data.map_rows_number)
	{
		y = 0;
		while (y < game_data->map_data.map_columns_number)
		{
			if (get_and_draw_image(game_data, map_items, x, y) == EXIT_FAILURE)
				return (EXIT_FAILURE);
			++y;
		}
		++x;
	}
	return (EXIT_SUCCESS);
}

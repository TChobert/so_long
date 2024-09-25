/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:10:09 by tchobert          #+#    #+#             */
/*   Updated: 2024/09/25 19:18:58 by tchobert         ###   ########.fr       */
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

static int	draw_map_to_window(t_game_data	*game_data, t_map_item *map_items)
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

static void init_map_items(t_game_data *game_data, t_map_item *map_items)
{
	map_items[0] = (t_map_item){FLOOR_ITEM, &game_data->images_data.floor_img};
	map_items[1] = (t_map_item){WALL_ITEM, &game_data->images_data.wall_img};
	map_items[2] = (t_map_item){PLAYER_ITEM, &game_data->images_data.character_img};
	map_items[3] = (t_map_item){COLLECTIBLE_ITEM, &game_data->images_data.collectible_img};
	map_items[4] = (t_map_item){EXIT_ITEM, &game_data->images_data.exit_img};
	map_items[5] = (t_map_item){0, NULL};
}

int	run_game(t_game_data *game_data)
{
	t_map_item	map_items[6];

	init_map_items(game_data, map_items);
	if (draw_map_to_window(game_data, map_items) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	mlx_loop(game_data->mlx_data.mlx_ptr);
	return (EXIT_SUCCESS);
}




























// (void)game_data;
	// mlx_ptr = mlx_init();
	// if (mlx_ptr == NULL)
	// 	return (EXIT_FAILURE);
	// win_ptr = mlx_new_window(mlx_ptr, game_data->current_map_data.map_columns_number * TILE_SIZE, game_data->current_map_data.map_rows_number * TILE_SIZE, "Test");
	// img_ptr = mlx_xpm_file_to_image(mlx_ptr, "./assets/Untitled.xpm",
	// 		&img_width, &img_height);
	//get_character_starting_position(game_data->current_map_data.map_array, game_data->current_character_data.character_starting_coord);
	//mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, pixel_x, pixel_y);
	// if (img_ptr == NULL)
	// {
	// 	mlx_destroy_display(mlx_ptr);
	// 	return (EXIT_FAILURE);
	// }
	// if (win_ptr == NULL)
	// {
	// 	mlx_destroy_display(mlx_ptr);
	// 	return (EXIT_FAILURE);
	// }

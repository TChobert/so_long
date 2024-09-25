/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_launcher.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:10:09 by tchobert          #+#    #+#             */
/*   Updated: 2024/09/25 16:36:37 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int check_image_load(void *mlx_ptr, t_image_data *image_data)
{
	if (image_data->img_ptr == NULL)
	{
		mlx_destroy_display(mlx_ptr);
		exit(EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	init_game(t_game_data *game_data)
{
	game_data->mlx_data.mlx_ptr = mlx_init();
	if (game_data->mlx_data.mlx_ptr == NULL)
		return (EXIT_FAILURE);
	game_data->mlx_data.win_ptr = mlx_new_window(game_data->mlx_data.mlx_ptr,
				game_data->current_map_data.map_columns_number * TILE_SIZE,
				game_data->current_map_data.map_rows_number * TILE_SIZE,
				"so_long");
	if (game_data->mlx_data.win_ptr == NULL)
	{
		return (EXIT_FAILURE);
	}
}

int	run_game(t_game_data *game_data)
{
	if (init_game(game_data) == EXIT_FAILURE)
	{
		//game_routine_exit(game_data);
		return (EXIT_FAILURE);
	}
	if (load_images(game_data) == EXIT_FAILURE)
	{
		//game_routine_exit(game_data);
		return (EXIT_FAILURE);
	}
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

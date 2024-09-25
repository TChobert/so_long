/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_launcher.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:10:09 by tchobert          #+#    #+#             */
/*   Updated: 2024/09/25 17:48:13 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	launch_game(t_game_data *game_data)
{
	if (init_game(game_data) == EXIT_FAILURE)
	{
		//game_exit_routine(game_data);
		return (EXIT_FAILURE);
	}
	return (run_game(game_data));
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

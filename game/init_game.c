/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 16:35:55 by tchobert          #+#    #+#             */
/*   Updated: 2024/09/30 19:10:44 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	init_mlx_data(t_game_data *game_data)
{
	game_data->mlx_data.mlx_ptr = mlx_init();
	if (game_data->mlx_data.mlx_ptr == NULL)
		return (EXIT_FAILURE);
	game_data->mlx_data.win_ptr = mlx_new_window(game_data->mlx_data.mlx_ptr,
				game_data->map_data.map_columns_number * TILE_SIZE,
				game_data->map_data.map_rows_number * TILE_SIZE,
				"so_long");
	if (game_data->mlx_data.win_ptr == NULL)
	{
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	init_game(t_game_data *game_data)
{
	if (init_mlx_data(game_data) == EXIT_FAILURE)
	{
		return (EXIT_FAILURE);
	}
	get_character_position(game_data->map_data.map_array,
		game_data->character_data.character_coord);
	game_data->character_data.is_red_potion = false;
	game_data->character_data.is_on_exit = false;
	return (load_game_images(game_data));
}

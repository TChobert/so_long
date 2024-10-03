/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 16:35:55 by tchobert          #+#    #+#             */
/*   Updated: 2024/10/02 16:40:41 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	init_mlx_data(t_game_data *game_data)
{
	game_data->mlx_data.mlx_ptr = mlx_init();
	if (game_data->mlx_data.mlx_ptr == NULL)
		return (EXIT_FAILURE);
	if (load_game_images(game_data) == EXIT_FAILURE)
	{
		close_game(game_data);
	}
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

static void	init_game_basic_data(t_game_data *game_data)
{
	get_character_position(game_data->map_data.map_array,
		game_data->character_data.character_coord);
	game_data->character_data.is_on_exit = false;
}

int	init_game(t_game_data *game_data)
{
	if (init_mlx_data(game_data) == EXIT_FAILURE)
	{
		return (EXIT_FAILURE);
	}
	init_game_basic_data(game_data);
	return (EXIT_SUCCESS);
}

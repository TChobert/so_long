/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_potions_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 17:36:30 by tchobert          #+#    #+#             */
/*   Updated: 2024/10/04 16:14:06 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

// static void	place_red_potion_randomly(t_game_data *game_data,
// 				unsigned int red_potions_num)
// {
// 	const unsigned int	map_width = game_data->map_data.map_columns_number;
// 	const unsigned int	map_height = game_data->map_data.map_rows_number;
// 	unsigned int		x;
// 	unsigned int		y;
// 	unsigned int		i;

// 	i = 0;
// 	while (i < red_potions_num)
// 	{
// 		x = rand() % map_height;
// 		y = rand() % map_width;
// 		while (game_data->map_data.map_array[x][y] != FLOOR_ITEM)
// 		{
// 			x = rand() % map_height;
// 			y = rand() % map_width;
// 		}
// 		game_data->map_data.map_array[x][y] = RED_POTION_ITEM;
// 		++i;
// 	}
// }

// static void	place_green_potion_randomly(t_game_data *game_data,
// 			unsigned int green_potions_num)
// {
// 	const unsigned int	map_width = game_data->map_data.map_columns_number;
// 	const unsigned int	map_height = game_data->map_data.map_rows_number;
// 	unsigned int		x;
// 	unsigned int		y;
// 	unsigned int		i;

// 	i = 0;
// 	while (i < green_potions_num)
// 	{
// 		x = rand() % map_height;
// 		y = rand() % map_width;
// 		while (game_data->map_data.map_array[x][y] != FLOOR_ITEM)
// 		{
// 			x = rand() % map_height;
// 			y = rand() % map_width;
// 		}
// 		game_data->map_data.map_array[x][y] = GREEN_POTION_ITEM;
// 		++i;
// 	}
// }

// static void	place_black_potions_randomly(t_game_data *game_data,
// 			unsigned int black_potions_num)
// {
// 	const unsigned int	map_width = game_data->map_data.map_columns_number;
// 	const unsigned int	map_height = game_data->map_data.map_rows_number;
// 	unsigned int		x;
// 	unsigned int		y;
// 	unsigned int		i;

// 	i = 0;
// 	while (i < black_potions_num)
// 	{
// 		x = rand() % map_height;
// 		y = rand() % map_width;
// 		while (game_data->map_data.map_array[x][y] != FLOOR_ITEM)
// 		{
// 			x = rand() % map_height;
// 			y = rand() % map_width;
// 		}
// 		game_data->map_data.map_array[x][y] = BLACK_POTION_ITEM;
// 		++i;
// 	}
// }

static void	place_yellow_potions_randomly(t_game_data *game_data,
			unsigned int yellow_potions_num)
{
	const unsigned int	map_width = game_data->map_data.map_columns_number;
	const unsigned int	map_height = game_data->map_data.map_rows_number;
	unsigned int		x;
	unsigned int		y;
	unsigned int		i;

	i = 0;
	while (i < yellow_potions_num)
	{
		x = rand() % map_height;
		y = rand() % map_width;
		while (game_data->map_data.map_array[x][y] != FLOOR_ITEM)
		{
			x = rand() % map_height;
			y = rand() % map_width;
		}
		game_data->map_data.map_array[x][y] = YELLOW_POTION_ITEM;
		++i;
	}
}

// static void	place_blue_potions_randomly(t_game_data *game_data,
// 			unsigned int blue_potions_num)
// {
// 	const unsigned int	map_width = game_data->map_data.map_columns_number;
// 	const unsigned int	map_height = game_data->map_data.map_rows_number;
// 	unsigned int		x;
// 	unsigned int		y;
// 	unsigned int		i;

// 	i = 0;
// 	while (i < blue_potions_num)
// 	{
// 		x = rand() % map_height;
// 		y = rand() % map_width;
// 		while (game_data->map_data.map_array[x][y] != FLOOR_ITEM)
// 		{
// 			x = rand() % map_height;
// 			y = rand() % map_width;
// 		}
// 		game_data->map_data.map_array[x][y] = BLUE_POTION_ITEM;
// 		++i;
// 	}
// }

void	place_potions_randomly(t_game_data *game_data)
{
	if (check_map_free_size_for_potions(game_data, 1)
		== POTIONS_CORRECT_MAP_SIZE)
	{
		srand(time(NULL));
	//	place_red_potion_randomly(game_data, 1);
	//	place_green_potion_randomly(game_data, 1);
	//	place_black_potions_randomly(game_data, 1);
		place_yellow_potions_randomly(game_data, 1);
	//	place_blue_potions_randomly(game_data, 1);
	}
	else
		ft_dprintf(STDERR_FILENO, "Bonus: Error\n"
			"Not enough free space for potions.\n");
}

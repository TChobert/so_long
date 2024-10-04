/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_potions_by_color_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 17:33:27 by tchobert          #+#    #+#             */
/*   Updated: 2024/10/04 17:34:21 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	place_red_potion_randomly(t_game_data *game_data,
				unsigned int red_potions_num)
{
	const unsigned int	map_width = game_data->map_data.map_columns_number;
	const unsigned int	map_height = game_data->map_data.map_rows_number;
	unsigned int		x;
	unsigned int		y;
	unsigned int		i;

	i = 0;
	while (i < red_potions_num)
	{
		x = rand() % map_height;
		y = rand() % map_width;
		while (game_data->map_data.map_array[x][y] != FLOOR_ITEM)
		{
			x = rand() % map_height;
			y = rand() % map_width;
		}
		game_data->map_data.map_array[x][y] = RED_POTION_ITEM;
		++i;
	}
}

void	place_green_potion_randomly(t_game_data *game_data,
			unsigned int green_potions_num)
{
	const unsigned int	map_width = game_data->map_data.map_columns_number;
	const unsigned int	map_height = game_data->map_data.map_rows_number;
	unsigned int		x;
	unsigned int		y;
	unsigned int		i;

	i = 0;
	while (i < green_potions_num)
	{
		x = rand() % map_height;
		y = rand() % map_width;
		while (game_data->map_data.map_array[x][y] != FLOOR_ITEM)
		{
			x = rand() % map_height;
			y = rand() % map_width;
		}
		game_data->map_data.map_array[x][y] = GREEN_POTION_ITEM;
		++i;
	}
}

void	place_black_potions_randomly(t_game_data *game_data,
			unsigned int black_potions_num)
{
	const unsigned int	map_width = game_data->map_data.map_columns_number;
	const unsigned int	map_height = game_data->map_data.map_rows_number;
	unsigned int		x;
	unsigned int		y;
	unsigned int		i;

	i = 0;
	while (i < black_potions_num)
	{
		x = rand() % map_height;
		y = rand() % map_width;
		while (game_data->map_data.map_array[x][y] != FLOOR_ITEM)
		{
			x = rand() % map_height;
			y = rand() % map_width;
		}
		game_data->map_data.map_array[x][y] = BLACK_POTION_ITEM;
		++i;
	}
}

void	place_yellow_potions_randomly(t_game_data *game_data,
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

void	place_blue_potions_randomly(t_game_data *game_data,
			unsigned int blue_potions_num)
{
	const unsigned int	map_width = game_data->map_data.map_columns_number;
	const unsigned int	map_height = game_data->map_data.map_rows_number;
	unsigned int		x;
	unsigned int		y;
	unsigned int		i;

	i = 0;
	while (i < blue_potions_num)
	{
		x = rand() % map_height;
		y = rand() % map_width;
		while (game_data->map_data.map_array[x][y] != FLOOR_ITEM)
		{
			x = rand() % map_height;
			y = rand() % map_width;
		}
		game_data->map_data.map_array[x][y] = BLUE_POTION_ITEM;
		++i;
	}
}

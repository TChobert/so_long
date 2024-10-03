/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_potions_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 17:36:30 by tchobert          #+#    #+#             */
/*   Updated: 2024/10/03 19:51:28 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static t_potions_map_size	check_map_free_size_for_potions(
								t_game_data *game_data,
								unsigned int total_potions_asked)
{
	size_t			x;
	size_t			y;
	size_t			free_space;

	x = 0;
	free_space = 0;
	while (x < game_data->map_data.map_rows_number)
	{
		y = 0;
		while (y < game_data->map_data.map_columns_number)
		{
			if (game_data->map_data.map_array[x][y] == FLOOR_ITEM)
				++free_space;
			++y;
		}
		++x;
	}
	if (free_space < total_potions_asked)
	{
		return (POTIONS_INCORRECT_MAP_SIZE);
	}
	return (POTIONS_CORRECT_MAP_SIZE);
}

static void	place_red_potion_randomly(t_game_data *game_data,
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

static void	place_green_potion_randomly(t_game_data *game_data,
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

static void	place_black_potions_randomly(t_game_data *game_data,
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

void	place_potions_randomly(t_game_data *game_data,
			unsigned int red_potions_num,
			unsigned int green_potions_num, unsigned int black_potions_num)
{
	if (check_map_free_size_for_potions(game_data, red_potions_num
			+ green_potions_num
			+ black_potions_num) == POTIONS_CORRECT_MAP_SIZE)
	{
		srand(time(NULL));
		place_red_potion_randomly(game_data, red_potions_num);
		place_green_potion_randomly(game_data, green_potions_num);
		place_black_potions_randomly(game_data, black_potions_num);
	}
	else
		ft_dprintf(STDERR_FILENO, "Bonus: Error\n"
			"Not enough free space for potions.\n");
}

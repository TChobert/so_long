/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_free_size_for_potions_bonus.c            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 13:06:05 by tchobert          #+#    #+#             */
/*   Updated: 2024/10/04 13:34:37 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_potions_map_size	check_map_free_size_for_potions(
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

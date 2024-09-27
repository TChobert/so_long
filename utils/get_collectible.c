/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_collectible.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:40:31 by tchobert          #+#    #+#             */
/*   Updated: 2024/09/27 14:40:58 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_collectible(t_game_data *game_data, unsigned int *character_new_coords)
{
	if (game_data->map_data.map_array[character_new_coords[0]][character_new_coords[1]] == COLLECTIBLE_ITEM)
	{
		if (game_data->map_data.items_values.collectibles_number > 0)
		game_data->map_data.items_values.collectibles_number -= 1;
	}
}

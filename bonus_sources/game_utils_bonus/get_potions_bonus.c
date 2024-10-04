/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_potions_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 13:10:30 by tchobert          #+#    #+#             */
/*   Updated: 2024/10/04 17:37:32 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	get_potions(t_game_data *game_data,
						unsigned int *character_new_coords)
{
	get_red_potion(game_data, character_new_coords);
	get_green_potion(game_data, character_new_coords);
	get_black_potion(game_data, character_new_coords);
	get_yellow_potion(game_data, character_new_coords);
	get_blue_potion(game_data, character_new_coords);
}

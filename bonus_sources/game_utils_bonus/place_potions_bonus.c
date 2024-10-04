/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_potions_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 17:36:30 by tchobert          #+#    #+#             */
/*   Updated: 2024/10/04 17:33:51 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	place_potions_randomly(t_game_data *game_data)
{
	if (check_map_free_size_for_potions(game_data, 5)
		== POTIONS_CORRECT_MAP_SIZE)
	{
		srand(time(NULL));
		place_red_potion_randomly(game_data, 1);
		place_green_potion_randomly(game_data, 1);
		place_black_potions_randomly(game_data, 1);
		place_yellow_potions_randomly(game_data, 1);
		place_blue_potions_randomly(game_data, 1);
	}
	else
		ft_dprintf(STDERR_FILENO, "Bonus: Error\n"
			"Not enough free space for potions.\n");
}

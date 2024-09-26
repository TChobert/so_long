/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_character_position.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 18:54:24 by tchobert          #+#    #+#             */
/*   Updated: 2024/09/26 18:42:12 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_character_position(char **map_array, unsigned int *player_coords)
{
	unsigned int	x;
	unsigned int	y;

	x = 0;
	while(map_array[x] != NULL)
	{
		y = 0;
		while (map_array[x][y] != '\0')
		{
			if (map_array[x][y] == 'P')
			{
				player_coords[0] = x;
				player_coords[1] = y;
				return ;
			}
			++y;
		}
		++x;
	}
	return ;
}

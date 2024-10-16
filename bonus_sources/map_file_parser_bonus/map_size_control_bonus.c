/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_size_control_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 18:43:16 by tchobert          #+#    #+#             */
/*   Updated: 2024/10/03 19:52:52 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_map_status	map_size_control(t_game_data *game_data)
{
	if (game_data->map_data.map_rows_number > 28
		|| game_data->map_data.map_columns_number > 50)
	{
		return (INVALID_MAP);
	}
	return (VALID_MAP);
}

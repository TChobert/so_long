/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_launcher.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:10:09 by tchobert          #+#    #+#             */
/*   Updated: 2024/10/02 13:50:11 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	launch_game(t_game_data *game_data)
{
	if (init_game(game_data) == EXIT_FAILURE)
	{
		close_game(game_data);
		return (EXIT_FAILURE);
	}
	return (run_game(game_data));
}

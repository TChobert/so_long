/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:38:44 by tchobert          #+#    #+#             */
/*   Updated: 2024/10/04 15:26:06 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	so_long(char *map)
{
	t_game_data	game_data;

	ft_bzero(&game_data, sizeof(game_data));
	if (map_file_parser(map, &game_data) == INVALID_MAP)
	{
		return (EXIT_FAILURE);
	}
	if (launch_game(&game_data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	if (ac != 2 || av[1] == NULL)
	{
		ft_dprintf(STDERR_FILENO, "Error\nPlease enter a map file.\n");
		return (EXIT_FAILURE);
	}
	return (so_long(av[1]));
}

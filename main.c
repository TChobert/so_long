/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:38:44 by tchobert          #+#    #+#             */
/*   Updated: 2024/09/25 15:41:54 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	so_long(char *map)
{
	t_game_data	game_data;

	ft_bzero(&game_data, sizeof(game_data));
	if (map_file_parser(map, &game_data) == INVALID_MAP)
	{
		ft_dprintf(STDERR_FILENO, "%s is not a correct map\n", map);
		return (EXIT_FAILURE);
	}
	ft_printf("%s is a correct map !\n", map);
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

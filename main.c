/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:38:44 by tchobert          #+#    #+#             */
/*   Updated: 2024/09/21 14:18:49 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_game_data	game_data;

	ft_bzero(&game_data, sizeof(game_data));
	if (ac != 2 || av[1] == NULL)
	{
		ft_dprintf(STDERR_FILENO, "Error\nPlease enter one map file\n");
		return (EXIT_FAILURE);
	}
	if (map_file_parser(av[1], &game_data) == INVALID_MAP)
	{
		ft_dprintf(STDERR_FILENO, "%s is not a correct map\n", av[1]);
		return (EXIT_FAILURE);
	}
	ft_printf("%s is a correct map !\n", av[1]);
	return (EXIT_SUCCESS);
}

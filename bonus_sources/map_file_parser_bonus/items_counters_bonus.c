/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   items_counters_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:59:12 by tchobert          #+#    #+#             */
/*   Updated: 2024/10/03 19:52:24 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

unsigned int	count_collectibles_items(const char *line)
{
	size_t			i;
	unsigned int	collectibles_items_count;

	i = 0;
	collectibles_items_count = 0;
	while (line[i] != '\0')
	{
		if (line[i] == COLLECTIBLE_ITEM)
		{
			++collectibles_items_count;
		}
		++i;
	}
	return (collectibles_items_count);
}

unsigned int	count_player_items(const char *line)
{
	size_t			i;
	unsigned int	player_items_count;

	i = 0;
	player_items_count = 0;
	while (line[i] != '\0')
	{
		if (line[i] == PLAYER_ITEM)
		{
			++player_items_count;
		}
		++i;
	}
	return (player_items_count);
}

unsigned int	count_exit_items(const char *line)
{
	size_t			i;
	unsigned int	exit_items_count;

	i = 0;
	exit_items_count = 0;
	while (line[i] != '\0')
	{
		if (line[i] == EXIT_ITEM)
		{
			++exit_items_count;
		}
		++i;
	}
	return (exit_items_count);
}

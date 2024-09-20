/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_file_type.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:41:33 by tchobert          #+#    #+#             */
/*   Updated: 2024/09/20 17:10:32 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	is_not_hide_ber_file(const char *map_file_path)
{
	const size_t	len = ft_strlen(map_file_path);

	if (strncmp(map_file_path + len - 5, "/.ber", len) == 0)
		return (false);
	return (true);
}

t_opening_status	check_map_file_type(const char *map_file_path)
{
	//split si PATH
	//strchr /
	//test strcmp .ber
	size_t	len;

	len = ft_strlen(map_file_path);
	if (len < 5 || ft_strncmp(map_file_path + len - 4, BER_SUFFIX, strlen(map_file_path)) != 0 || is_not_hide_ber_file(map_file_path) == false)
	{
		ft_dprintf(STDERR_FILENO, "Error\nInvalid map file type. Please enter '%s' file\n", BER_SUFFIX);
		return (INVALID_FILE_TYPE);
	}
	return (VALID_FILE_TYPE);
}

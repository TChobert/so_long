/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_file_type.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:41:33 by tchobert          #+#    #+#             */
/*   Updated: 2024/09/20 15:41:24 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_opening_status	check_map_file_type(const char *map_file_path)
{
	//split si PATH
	//strchr /
	//test strcmp .ber
	size_t	len;

	len = ft_strlen(map_file_path);
	if (len < 5 || ft_strncmp(map_file_path + len - 4, BER_SUFFIX, strlen(map_file_path)) != 0)
	{
				ft_dprintf(STDERR_FILENO, "Error\nInvalid map file type. Please enter '%s' file\n", BER_SUFFIX);
		return (INVALID_FILE_TYPE);
	}
	return (VALID_FILE_TYPE);
}

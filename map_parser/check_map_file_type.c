/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:41:33 by tchobert          #+#    #+#             */
/*   Updated: 2024/09/19 12:54:05 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_opening_status	check_map_file_type(const char *map_file_path)
{
	//split si PATH
	//strchr /
	//test strcmp .ber

	const char		*file_suffix_position = map_file_path + (ft_strlen(map_file_path) - 4);

	if (ft_strcmp(file_suffix_position, BER_SUFFIX) != 0
		|| ft_strcmp(map_file_path, BER_SUFFIX) == 0)
	{
		return (INVALID_FILE_TYPE);
	}
	return (VALID_FILE_TYPE);
}

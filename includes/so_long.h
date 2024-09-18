/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 14:27:28 by tchobert          #+#    #+#             */
/*   Updated: 2024/09/18 14:55:34 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// INCLUDES //

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <errno.h>

# include "libft.h"

// DEFINES //

# define BER_SUFFIX ".ber"

// TYPEDEFS //

typedef enum	e_opening_status
{
	INVALID_FILE_TYPE,
	VALID_FILE_TYPE,
	OPENING_ERROR,
	OPENING_SUCCESS
}				t_opening_status;

typedef enum	e_map_status
{
	INVALID_MAP,
	VALID_MAP
}				t_map_status;

// PROTOTYPES //

void				display_opening_errors(const char *map_file_path);
t_map_status		map_parsing(const char *map_file_path);
t_opening_status	check_map_file_type(const char *map_file_path);

# endif

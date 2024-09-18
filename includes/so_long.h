/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 14:27:28 by tchobert          #+#    #+#             */
/*   Updated: 2024/09/18 18:37:39 by tchobert         ###   ########.fr       */
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

# define WALL 1

# define BER_SUFFIX ".ber"

// TYPEDEFS //

typedef enum	e_items_types
{
	PLAYER_ITEM,
	COLLECTIBLE_ITEM,
	WALL_ITEM,
	EXIT_ITEM
}				t_items_types;

typedef enum	e_opening_status
{
	INVALID_FILE_TYPE,
	VALID_FILE_TYPE,
	OPENING_ERROR,
	OPENING_SUCCESS
}				t_opening_status;

typedef enum	e_map_line_status
{
	INVALID_LINE,
	VALID_LINE
}				t_map_line_status;

typedef enum	e_map_status
{
	INVALID_MAP,
	VALID_MAP
}				t_map_status;

typedef struct	s_items_values
{
	unsigned int	collectibles_number;
	unsigned int	player_number;
	unsigned int	exit_number;
}				t_items_values;

typedef struct	s_map_data
{
	t_items_values	items_values;
	size_t			first_line_size;
	size_t			map_lines_number;

}				t_map_data;

// PROTOTYPES //

void				display_opening_errors(const char *map_file_path);
t_map_status		map_parsing(const char *map_file_path);
t_opening_status	check_map_file_type(const char *map_file_path);

# endif

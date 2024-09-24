/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 14:27:28 by tchobert          #+#    #+#             */
/*   Updated: 2024/09/24 15:54:51 by tchobert         ###   ########.fr       */
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

# include "mlx.h"
# include "libft.h"

// DEFINES //

# define ITEM_STR "01PEC"
# define WALL '1'
# define BER_SUFFIX ".ber"

// TYPEDEFS //

typedef enum	e_items_types
{
	PLAYER_ITEM = 'P',
	COLLECTIBLE_ITEM = 'C',
	WALL_ITEM = '1',
	EXIT_ITEM = 'E'
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
	char			**map_array;
	t_items_values	items_values;
	size_t			map_rows_number;
	size_t			map_columns_number;

}				t_map_data;

typedef struct	s_character_data
{
	int		character_starting_coord[2];
	int		character_current_coord[2];
}				t_character_data;

typedef struct	s_game_data
{
	t_map_data			current_map_data;
	t_character_data	current_character_data;

}				t_game_data;


// PROTOTYPES //

// PARSING

t_opening_status	open_map_file(const char *map_file_path, int *map_fd);
void				display_opening_errors(const char *map_file_path);
t_map_status		map_file_parser(const char *map_file_path, t_game_data *game_data);
t_opening_status	check_map_file_type(const char *map_file_path);
char				**build_map_array(int map_file_fd, t_game_data *game_data);
t_map_status		map_array_lines_controls(t_game_data *game_data);
t_map_line_status	check_first_line(const char *first_line,
						t_game_data *game_data);
t_map_line_status	check_last_line(const char *last_line, t_game_data *game_data);
t_map_line_status	check_line(const char *line, t_game_data *game_data);
t_map_line_status	check_line_items(const char *line);
unsigned int		count_collectibles_items(const char *line);
unsigned int		count_player_items(const char *line);
unsigned int		count_exit_items(const char *line);
size_t				get_line_size(const char *line);
void				add_line_data(const char *line, t_game_data *game_data);
bool				is_full_wall(const char *line);
bool				is_correct_size(const char *line, t_game_data *game_data);
bool				is_surrounded_by_walls(const char *line, t_game_data *game_data);
t_map_status		launch_flood_fill(t_game_data game_data);
int 				flood_fill(t_game_data *game_data, char **duplicated_map, size_t x, size_t y);
char				**duplicate_map_array(t_game_data game_data);
void				get_character_starting_position(char **map_array, size_t *character_coords);
void				close_and_free_routine(int map_fd, t_game_data *game_data);

// GAME

int	launch_game(t_game_data *game_data);

# endif

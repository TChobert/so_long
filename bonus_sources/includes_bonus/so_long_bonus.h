/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 14:27:28 by tchobert          #+#    #+#             */
/*   Updated: 2024/10/04 16:45:12 by tchobert         ###   ########.fr       */
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
# include <X11/X.h>
# include <X11/keysym.h>
# include <time.h>
# include <sys/time.h>

# include "mlx.h"
# include "libft.h"

// DEFINES //

# define KNRM  "\x1B[0m"
# define KRED  "\x1B[31m"
# define KGRN  "\x1B[32m"
# define KYEL  "\x1B[33m"
# define KBLU  "\x1B[34m"
# define KMAG  "\x1B[35m"
# define KCYN  "\x1B[36m"

# define ITEM_STR "01CEP"
# define WALL '1'
# define BER_SUFFIX ".ber"
# define TILE_SIZE 32

# define KEY_W_INDEX 0
# define KEY_A_INDEX 1
# define KEY_D_INDEX 2
# define KEY_S_INDEX 3
# define KEY_ESC_INDEX 4

// TYPEDEFS //

typedef enum e_move_status
{
	VALID_MOVE,
	INVALID_MOVE,
	EXIT_MOVE
}			t_move_status;

typedef enum e_items_types
{
	FLOOR_ITEM = '0',
	WALL_ITEM = '1',
	PLAYER_ITEM = 'P',
	COLLECTIBLE_ITEM = 'C',
	EXIT_ITEM = 'E',
	RED_POTION_ITEM = 'R',
	GREEN_POTION_ITEM = 'G',
	BLACK_POTION_ITEM = 'B',
	YELLOW_POTION_ITEM = 'Y',
	BLUE_POTION_ITEM = 'Z'
}			t_items_types;

typedef enum e_potions_map_size
{
	POTIONS_INCORRECT_MAP_SIZE,
	POTIONS_CORRECT_MAP_SIZE
}			t_potions_map_size;

typedef enum e_key_codes
{
	W_KEY = 119,
	A_KEY = 97,
	D_KEY = 100,
	S_KEY = 115,
	ESC_KEY = 65307
}			t_key_codes;

typedef enum e_opening_status
{
	INVALID_FILE_TYPE,
	VALID_FILE_TYPE,
	OPENING_ERROR,
	OPENING_SUCCESS
}			t_opening_status;

typedef enum e_map_line_status
{
	INVALID_LINE,
	VALID_LINE
}			t_map_line_status;

typedef enum e_map_status
{
	INVALID_MAP,
	VALID_MAP
}			t_map_status;

typedef enum e_invalid_map_nature
{
	NO_PROBLEM,
	NOT_CONFORM_MAP,
	NOT_CONFORM_SIZE,
	DOUBLE_ITEM,
	NO_PATH
}			t_invalid_map_nature;

typedef struct s_items_values
{
	unsigned int	collectibles_number;
	unsigned int	player_number;
	unsigned int	exit_number;
}				t_items_values;

typedef struct s_map_data
{
	char					**map_array;
	t_items_values			items_values;
	size_t					map_rows_number;
	size_t					map_columns_number;
}			t_map_data;

typedef struct s_character_data
{
	unsigned int	character_coord[2];
	unsigned int	moves_counter;
	bool			is_right;
	bool			is_red_potion;
	bool			is_black_potion;
	bool			is_yellow_potion;
	bool			is_blue_potion;
	bool			is_on_exit;
}			t_character_data;

typedef struct s_image_data
{
	void	*img_ptr;
	int		width;
	int		height;
}			t_image_data;

typedef struct s_images_data
{
	bool			is_images_loaded;
	t_image_data	hedgehog_left_img;
	t_image_data	hedgehog_right_img;
	t_image_data	bear_right_img;
	t_image_data	bear_left_img;
	t_image_data	sanic_right_img;
	t_image_data	sanic_left_img;
	t_image_data	sanic_exit_left_img;
	t_image_data	sanic_exit_right_img;
	t_image_data	crab_img;
	t_image_data	crab_exit_img;
	t_image_data	collectible_img;
	t_image_data	exit_img;
	t_image_data	wall_img;
	t_image_data	floor_img;
	t_image_data	red_potion_img;
	t_image_data	green_potion_img;
	t_image_data	black_potion_img;
	t_image_data	blue_potion_img;
	t_image_data	yellow_potion_img;
	t_image_data	hedgehog_exit_right_img;
	t_image_data	hedgehog_exit_left_img;
	t_image_data	bear_exit_right_img;
	t_image_data	bear_exit_left_img;
}			t_images_data;

typedef struct s_mlx_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}			t_mlx_data;

typedef struct s_map_item
{
	char			item;
	t_image_data	*image_data;
}				t_map_item;

typedef struct s_game_data
{
	t_map_data			map_data;
	t_character_data	character_data;
	t_mlx_data			mlx_data;
	t_images_data		images_data;
}			t_game_data;

typedef t_move_status	(*t_key_press_functions)(t_game_data *);

// PROTOTYPES //

// PARSING

t_opening_status	open_map_file(const char *map_file_path, int *map_fd);
void				display_opening_errors(const char *map_file_path);
void				display_parsing_errors(
						t_invalid_map_nature map_problem_status);
t_map_status		map_file_parser(const char *map_file_path,
						t_game_data *game_data);
t_opening_status	check_map_file_type(const char *map_file_path);
char				**build_map_array(int map_file_fd, t_game_data *game_data);
t_map_status		map_array_lines_controls(t_game_data *game_data,
						t_invalid_map_nature *map_problem_status);
t_map_line_status	check_first_line(const char *first_line,
						t_game_data *game_data);
t_map_line_status	check_last_line(const char *last_line,
						t_game_data *game_data);
t_map_line_status	check_line(const char *line, t_game_data *game_data);
t_map_line_status	check_line_items(const char *line);
unsigned int		count_collectibles_items(const char *line);
unsigned int		count_player_items(const char *line);
unsigned int		count_exit_items(const char *line);
size_t				get_line_size(const char *line);
void				add_line_data(const char *line, t_game_data *game_data);
bool				is_full_wall(const char *line);
bool				is_correct_size(const char *line, t_game_data *game_data);
bool				is_surrounded_by_walls(const char *line,
						t_game_data *game_data);
t_map_status		launch_flood_fill(t_game_data game_data);
int					flood_fill(t_game_data *game_data,
						char **duplicated_map, size_t x, size_t y);
char				**duplicate_map_array(t_game_data game_data);
void				close_and_free_routine(int map_fd, t_game_data *game_data);
t_map_status		map_size_control(t_game_data *game_data);

// GAME

int					launch_game(t_game_data *game_data);
int					init_game(t_game_data *game_data);
int					load_image(t_game_data *game_data, t_image_data *image_data,
						const char *file_path);
int					load_game_images(t_game_data *game_data);
int					run_game(t_game_data *game_data);

int					draw_map_to_window(t_game_data	*game_data,
						t_map_item *map_items);

void				update_character_position(t_game_data *game_data,
						unsigned int *character_new_coords);
void				update_and_print_character_position(t_game_data *game_data,
						unsigned int *character_new_coords);

void				print_sanic_position(t_game_data *game_data,
									unsigned int *old_character_coords);
void				print_crab_position(t_game_data *game_data,
									unsigned int *old_character_coords);
void				print_bear_position(t_game_data *game_data,
										unsigned int *old_character_coords);
void				print_hedgehog_position(t_game_data *game_data,
										unsigned int *old_character_coords);

int					define_keycode_to_move_function(int keycode);
int					reverse_define_keycode_to_move_function(int keycode);

t_move_status		move_up(t_game_data *game_data);
t_move_status		move_left(t_game_data *game_data);
t_move_status		move_right(t_game_data *game_data);
t_move_status		move_down(t_game_data *game_data);

t_move_status		close_game(t_game_data *game_data);

t_move_status		check_move_status(t_game_data *game_data,
						unsigned int *character_new_coords);
t_move_status		check_exit_move(t_game_data *game_data,
						unsigned int *character_new_coords);

int					draw_image(t_game_data *game_data, t_image_data *image_data,
						size_t x, size_t y);

int					cross_click(t_game_data *game_data);

// UTILS

void				get_collectible(t_game_data *game_data,
						unsigned int *character_new_coords);
void				get_character_position(char **map_array,
						unsigned int *character_coords);
t_move_status		close_game(t_game_data *game_data);
void				get_potions(t_game_data *game_data,
						unsigned int *character_new_coords);
void				place_potions_randomly(t_game_data *game_data);
t_potions_map_size	check_map_free_size_for_potions(t_game_data *game_data,
						unsigned int total_potions_asked);

void				display_hedgehog(char *color);
void				display_book(char *color);

#endif

## COLORS ##

GREEN =\033[0;32m
YELLOW =\033[0;33m
RESET =\033[0m

##### VARIABLES #####

## TARGET ##

NAME := so_long

## TARGET BONUS ##

BONUS_NAME := so_long_bonus

## LIBFT ##

LIBFT_DIR := ./libft
LIBFT := $(LIBFT_DIR)/libft.a
LIBFT_INCLUDES_DIR := $(LIBFT_DIR)/includes
LIBFT_HEADER := $(LIBFT_INCLUDES_DIR)/libft.h

## MLX ##

MLX_DIR = ./minilibx-linux
MLX = $(MLX_DIR)/libmlx_Linux.a
MLX_INCLUDES_DIR = $(MLX_DIR)
MLX_HEADER = $(MLX_INCLUDES_DIR)/mlx.h

## MLX_LINKS ##

MLX_LINKS += -L/usr/lib
MLX_LINKS += -lXext
MLX_LINKS += -lX11
MLX_LINKS += -lm
MLX_LINKS += -lz
#MLX_LINKS += -lbsd

## COMPILATION ##

CC := cc

CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -Werror

ifeq ($(d), 1)
	CFLAGS += -g3
endif

ifeq ($(d), 2)
	CFLAGS += -fsanitize=address,undefined -g3
endif

ifeq ($(d), 3)
	CC=clang
	CFLAGS=-Weverything
endif

### SOURCES MANDATORY PART ###

SRCS_DIR += ./sources
SRCS_DIR += ./sources/map_file_parser
SRCS_DIR += ./sources/game
SRCS_DIR += ./sources/game_utils

# map parsing #

SRCS += open_map_file.c
SRCS += map_file_parser.c
SRCS += check_map_file_type.c
SRCS += build_map_array.c
SRCS += map_array_lines_controls.c
SRCS += map_lines_checkers.c
SRCS += map_lines_checkers_utils.c
SRCS += items_counters.c
SRCS += errors_displaying.c
SRCS += flood_fill.c
SRCS += add_line_data.c
SRCS += duplicate_map_array.c
SRCS += map_size_control.c

SRCS += close_and_free_routine.c

# game #

SRCS += game_launcher.c
SRCS += init_game.c
SRCS += load_game_images.c
SRCS += run_game.c
SRCS += draw_map_to_window.c
SRCS += draw_image.c
SRCS += moves_checkers.c
SRCS += update_and_print_character_position.c
SRCS += character_moves.c

# game utils #

SRCS += get_character_position.c
SRCS += get_collectible.c
SRCS += close_game.c
SRCS += display_ascii_arts.c

# main #

SRCS += main.c

vpath %.c $(SRCS_DIR)

## HEADERS MANDATORY ##

HEADERS := so_long.h

INCLUDES_DIR := ./sources/includes

vpath %.h $(INCLUDES_DIR)

## OBJECTS ##

OBJS_DIR := ./sources/objs

OBJS := $(patsubst %.c, $(OBJS_DIR)/%.o, $(SRCS))



### SOURCES BONUS PART ###

BONUS_DIR += ./bonus_sources
BONUS_DIR += ./bonus_sources/game_bonus
BONUS_DIR += ./bonus_sources/game_utils_bonus
BONUS_DIR += ./bonus_sources/map_file_parser_bonus

# map parsing #

BONUS += add_line_data_bonus.c
BONUS += build_map_array_bonus.c
BONUS += check_map_file_type_bonus.c
BONUS += close_and_free_routine_bonus.c
BONUS += duplicate_map_array_bonus.c
BONUS += errors_displaying_bonus.c
BONUS += flood_fill_bonus.c
BONUS += items_counters_bonus.c
BONUS += map_array_lines_controls_bonus.c
BONUS += map_file_parser_bonus.c
BONUS += map_lines_checkers_bonus.c
BONUS += map_lines_checkers_utils_bonus.c
BONUS += map_size_control_bonus.c
BONUS += open_map_file_bonus.c

# game #

BONUS += character_moves_bonus.c
BONUS += cross_click_bonus.c
BONUS += draw_image_bonus.c
BONUS += draw_map_to_window_bonus.c
BONUS += game_launcher_bonus.c
BONUS += init_game_bonus.c
BONUS += load_image_bonus.c
BONUS += load_game_images_bonus.c
BONUS += moves_checkers_bonus.c
BONUS += run_game_bonus.c
BONUS += update_and_print_character_position_bonus.c
BONUS += update_character_position_bonus.c
BONUS += print_sanic_position_bonus.c
BONUS += print_crab_position_bonus.c
BONUS += print_bear_position_bonus.c
BONUS += print_hedgehog_position_bonus.c
BONUS += define_keycode_to_move_functions.c
BONUS += load_hedgehog_images_bonus.c

# game utils #

BONUS += close_game_bonus.c
BONUS += display_ascii_arts_bonus.c
BONUS += get_character_position_bonus.c
BONUS += get_collectible_bonus.c
BONUS += place_potions_bonus.c
BONUS += get_potions_bonus.c
BONUS += get_potions_by_color_bonus.c
BONUS += check_map_free_size_for_potions_bonus.c
BONUS += place_potions_by_color_bonus.c
BONUS += destroy_potions_images_bonus.c
BONUS += destroy_characters_images_bonus.c

# main #

BONUS += main_bonus.c

vpath %.c $(BONUS_DIR)

## HEADERS BONUS ##

BONUS_HEADERS := so_long_bonus.h

BONUS_INCLUDES_DIR := ./bonus_sources/includes_bonus

vpath %.h $(BONUS_INCLUDES_DIR)

## OBJECTS BONUS ##

BONUS_OBJS_DIR := ./bonus_sources/bonus_objs

BONUS_OBJS := $(patsubst %.c, $(BONUS_OBJS_DIR)/%.o, $(BONUS))


##### RULES #####

all : $(LIBFT) $(MLX) $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) >/dev/null
	@echo "$(GREEN)Libft compiled !$(RESET)"

$(MLX):
	@$(MAKE) -C $(MLX_DIR) >/dev/null
	@echo "$(GREEN)Minilibx compiled !$(RESET)"

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(MLX_LINKS) -I$(LIBFT_INCLUDES_DIR) -I$(MLX_INCLUDES_DIR) -I$(INCLUDES_DIR) $(OBJS) $(LIBFT) $(MLX) -o $@
	@echo "$(GREEN)so_long compiled !$(RESET)"

bonus: $(LIBFT) $(MLX) $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	@$(CC) $(CFLAGS) $(MLX_LINKS) -I$(LIBFT_INCLUDES_DIR) -I$(MLX_INCLUDES_DIR) -I$(BONUS_INCLUDES_DIR) $(BONUS_OBJS) $(LIBFT) $(MLX) -o $@
	@echo "$(GREEN)so_long_bonus compiled !$(RESET)"
	@echo "$(YELLOW)ADVICE: BEWARE OF YELLOW POTIONS !$(RESET)"

# bonus: $(LIBFT) $(MLX) $(BONUS_OBJS)
# 	$(CC) $(CFLAGS) $(MLX_LINKS) -I$(LIBFT_INCLUDES_DIR) -I$(MLX_INCLUDES_DIR) -I$(BONUS_INCLUDES_DIR) $(BONUS_OBJS) $(LIBFT) $(MLX) -o $(BONUS_NAME)

$(OBJS): $(OBJS_DIR)/%.o: %.c $(HEADERS) | $(OBJS_DIR)
	@$(CC) $(CFLAGS) -I$(LIBFT_INCLUDES_DIR) -I$(MLX_INCLUDES_DIR) -I$(INCLUDES_DIR) -c $< -o $@

$(BONUS_OBJS): $(BONUS_OBJS_DIR)/%.o: %.c $(BONUS_HEADERS) | $(BONUS_OBJS_DIR)
	@$(CC) $(CFLAGS) -I$(LIBFT_INCLUDES_DIR) -I$(MLX_INCLUDES_DIR) -I$(BONUS_INCLUDES_DIR) -c $< -o $@

$(OBJS_DIR):
	@mkdir $@

$(BONUS_OBJS_DIR):
	@mkdir $@

clean:
	@$(RM) -R $(OBJS_DIR) $(BONUS_OBJS_DIR)
	@$(MAKE) -C $(LIBFT_DIR) fclean >/dev/null
	@$(MAKE) -C $(MLX_DIR) clean >/dev/null
	@echo "$(GREEN)Clean completed !$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(BONUS_NAME)
	@echo "$(GREEN)Full clean completed !$(RESET)"

re: fclean all

.PHONY: all clean fclean re bonus

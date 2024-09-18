##### VARIABLES #####

## TARGET ##

NAME := so_long

## LIBFT ##

LIBFT_DIR := ./libft
LIBFT := $(LIBFT_DIR)/libft.a
LIBFT_INCLUDES_DIR := $(LIBFT_DIR)/includes
LIBFT_HEADER := $(LIBFT_INCLUDES_DIR)/libft.h

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

## SOURCES ##

SRCS_DIR += map_parser
SRCS_DIR += tests

# tests #

#SRCS += test.c

# map parsing #

SRCS += map_parser.c
SRCS += parser_utils.c

# main #

SRCS += main.c

vpath %.c $(SRCS_DIR)

## HEADERS ##

HEADERS := so_long.h

INCLUDES_DIR := includes

vpath %.h $(INCLUDES_DIR)

## OBJECTS ##

OBJS_DIR := objs

OBJS := $(patsubst %.c, $(OBJS_DIR)/%.o, $(SRCS))


##### RULES #####

all : $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -I$(LIBFT_INCLUDES_DIR) -I$(INCLUDES_DIR) $(OBJS) $(LIBFT) -o $@

$(OBJS): $(OBJS_DIR)/%.o: %.c $(HEADERS) | $(OBJS_DIR)
	$(CC) $(CFLAGS) -I$(LIBFT_INCLUDES_DIR) -I$(INCLUDES_DIR) -c $< -o $@

$(OBJS_DIR):
	mkdir $@

clean:
	$(RM) -R $(OBJS_DIR)
	$(MAKE) -C $(LIBFT_DIR) fclean

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

NAME	= push_swap
DEBUG	= Outdebug

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
IFLAGS	= -Iinclude

SRC_DIR	= src
OBJ_DIR	= obj

SRC_FILES	= \
	push_swap.c \
	algo/adaptive.c \
	algo/algo_complex.c \
	algo/algo_medium.c \
	algo/algo_simple.c \
	algo/complex_index.c \
	algo/disorder.c \
	algo/medium_utils.c \
	algo/sort_one_three_five.c \
	ops/push.c \
	ops/reverserotate.c \
	ops/rotate.c \
	ops/stack_utils.c \
	ops/swap.c \
	parse/ft_atol.c \
	parse/ft_split.c \
	parse/ft_strncmp.c \
	parse/index_compression.c \
	parse/parser.c \
	bench/benchmark.c \
	bench/benchmark_utils.c

SRC		= $(addprefix $(SRC_DIR)/,$(SRC_FILES))
OBJ		= $(addprefix $(OBJ_DIR)/,$(SRC_FILES:.c=.o))

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)/algo
	@mkdir -p $(OBJ_DIR)/ops
	@mkdir -p $(OBJ_DIR)/parse
	@mkdir -p $(OBJ_DIR)/bench

$(NAME): $(OBJ_DIR) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

debug: CFLAGS += -g -O0
debug: $(OBJ_DIR) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(DEBUG)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) $(DEBUG)

re: fclean all

.PHONY: all clean fclean re debug

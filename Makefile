NAME	= push_swap
DEBUG	= Outdebug

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
IFLAGS	= -I.

SRC		= src/disorder.c \
		  src/ft_atol.c \
		  src/ft_split.c \
		  src/parser.c \
		  src/push_swap.c \
		  src/stack_utils.c \
		  src/benchmark.c \
		  src/ft_strncmp.c \
		  src/benchmark_utils.c\
		  op/push.c \
		  op/reverserotate.c \
		  op/rotate.c \
		  op/swap.c \
		  algo/simple_sort/algo_simple.c \
		  algo/simple_sort/sort_one_three_five.c \
		  algo/medium_sort/algo_medium.c \
		  algo/index_compression.c \
		  algo/adaptive.c \
		  algo/complex_sort/algo_complex.c \
		  algo/complex_sort/complex_index.c \
		  

OBJ		= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

debug: CFLAGS += -g -O0
debug: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(DEBUG)

%.o: %.c
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

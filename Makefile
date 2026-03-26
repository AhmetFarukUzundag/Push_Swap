NAME	= push_swap
DEBUG	= Outdebug

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
IFLAGS	= -I.

SRC		= disorder.c \
		  ft_atol.c \
		  ft_split.c \
		  parser.c \
		  push_swap.c \
		  stack_utils.c \
		  benchmark.c \
		  ft_strncmp.c \
		  benchmark_utils.c\
		  push.c \
		  reverserotate.c \
		  rotate.c \
		  swap.c \
		  algo_simple.c \
		  sort_one_three_five.c \
		  algo_medium.c \
		  medium_utils.c \
		  index_compression.c \
		  adaptive.c \
		  algo_complex.c \
		  complex_index.c 
		  

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

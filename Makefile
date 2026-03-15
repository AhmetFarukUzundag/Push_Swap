NAME	= push_swap
DEBUG	= Outdebug

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
IFLAGS	= -I.

SRC		= main.c \
		  src/disorder.c \
		  src/ft_atol.c \
		  src/ft_split.c \
		  src/parser.c \
		  src/push_swap.c \
		  src/stack_utils.c \
		  op/push.c \
		  op/reverserotate.c \
		  op/rotate.c \
		  op/swap.c \
		  algo/algo_simple.c

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

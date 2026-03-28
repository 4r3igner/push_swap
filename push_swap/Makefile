NAME        = push_swap
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g

SRC         = main.c	push_swap.c	push.c	rotate.c \
							reverse_rotate.c	stack_controls.c	swap.c
              

OBJ         = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

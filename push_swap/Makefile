NAME        = push_swap
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g

SRC         = main.c, utils.c, push_swap.c\
              # Append future source files here

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

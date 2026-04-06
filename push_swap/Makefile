NAME        = push_swap
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g

SRC         = main.c	bst_controls.c	convertor.c	engine.c \
							helper.c	list_controls.c	push.c	sort.c	\
							push_swap_utils.c	reverse_rotate.c	rotate.c	\
							swap.c	target.c	utils_2.c
              

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

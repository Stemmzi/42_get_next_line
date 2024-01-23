NAME = getnextline.a
SRCS = get_next_line.c get_next_line_utils.c main.c
OBJ = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

test: 
	cc $(CFLAGS) -g -D BUFFER_SIZE=10 $(SRCS) && ./a.out

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all test clean fclean re

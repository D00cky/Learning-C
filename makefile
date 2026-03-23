CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = hello

SRCS = hello.c
OBJS = $(SRCS:.c=.o)

ALL: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean ALL

.PHONY: all clean fclean re


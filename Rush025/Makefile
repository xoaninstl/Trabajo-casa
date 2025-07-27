NAME = rush-02

CC = gcc
CFLAGS = -Wextra -Wall -Werror

HEADERS = functions.h

SRC = main.c \
      functions.c \
      read.c \
      search.c \
      process_block.c

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

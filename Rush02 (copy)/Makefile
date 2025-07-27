# Nombre del ejecutable
NAME = rush-02

# Compilador y flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Archivos fuente (.c)
SRCS =	main.c \
		funciones.c \
		opendic.c \
		prepnum.c \
		text_converter.c

# Archivos objeto (.o)
OBJS = $(SRCS:.c=.o)

# Reglas
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

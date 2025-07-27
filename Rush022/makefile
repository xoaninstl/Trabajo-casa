# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcasan-a <dcasan-a@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/27 14:19:26 by dcasan-a          #+#    #+#              #
#    Updated: 2025/07/27 14:24:07 by dcasan-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rush-02

CC = gcc

CFLAGS = -Wextra -Wall -Werror

HEADERS = *.h

SRC = *.c

$(NAME):
	@$(CC) $(FLAGS) $(HEADERS) $(SRC) -o $(NAME)

PHONY: clean fclean

clean:
	@rm -f *.o
	@rm -f *.gch

fclean:
	@rm -f $(NAME)
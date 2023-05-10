# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joaoribe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/09 06:12:11 by joaoribe          #+#    #+#              #
#    Updated: 2023/05/09 06:12:19 by joaoribe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libgnl.a
CC	= gcc
CFLAGS	= -Wall -Wextra -Werror
SRC	= get_next_line.c get_next_line_utils.c
OBJ	= $(SRC:.c=.o)
BONUS	= get_next_line_bonus.c get_next_line_utils_bonus.c
BOBJ	= $(BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

bonus: $(BOBJ)
	ar rcs $(NAME) $(BOBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(BOBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus

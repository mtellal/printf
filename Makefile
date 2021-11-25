# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtellal <mtellal@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/05 16:08:37 by mtellal           #+#    #+#              #
#    Updated: 2021/11/25 09:44:14 by mtellal          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

SRC = \
      ft_printf.c \
      conversion_percent.c conversion_string.c conversion_char.c conversion_int.c conversion_hex.c \
     ft_printf_utils.c convertInt2Hex.c

OBJ = $(SRC:.c=.o)

LIB = libft/libft.a

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./libft
	cp $(LIB) $(NAME)
	$(CC) -c $(SRC) $(FLAGS)
	ar -rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

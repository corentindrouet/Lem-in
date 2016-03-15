# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/15 08:11:19 by cdrouet           #+#    #+#              #
#    Updated: 2016/03/15 13:22:14 by cdrouet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

SRC = main.c \
	  lst_file.c \
	  map_read.c \
	  ft_lst.c \

BIN = $(SRC:.c=.o)

FLAG = -Wall -Wextra -Werror

LIB = -Llibft/ -lftprintf

MLIB = make -C libft/

$(NAME) :
	gcc $(FLAG) -c $(SRC);
	gcc $(FLAG) -o $(NAME) $(BIN) $(LIB)

all : $(NAME)

clean : 
	rm -f $(BIN)

fclean : clean
	rm -f $(NAME)

re : fclean all

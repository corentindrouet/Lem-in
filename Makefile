# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/15 08:11:19 by cdrouet           #+#    #+#              #
#    Updated: 2016/03/22 13:36:30 by cdrouet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

SRC = main.c \
	  lst_file.c \
	  map_read.c \
	  ft_lst.c \
	  search_path.c \
	  ft_path.c \
	  search_path2.c \
	  tri_path.c \
	  ft_plus.c \
	  resolv.c \
	  ft_fourmis.c \
	  ft_plus2.c \
	  ft_path2.c \
	  search_path3.c \

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

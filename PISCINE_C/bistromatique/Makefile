# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbaudot <romain.baudot@gmail.com>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/07/29 09:18:42 by rbaudot           #+#    #+#              #
#    Updated: 2013/08/09 21:37:03 by rbaudot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = calc

SRC = add.c calc.c check_av.c ft_is_in.c ft_str.c list.c mult.c parent.c\
	  parse.c parse_dep.c rpn.c stack.c sub.c utilities.c

OUT = add.o calc.o check_av.o ft_is_in.o ft_str.o list.o mult.o parent.o\
	  parse.o parse_dep.o rpn.o stack.o sub.o utilities.o

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -I./ -o $(NAME) $(SRC)

clean:
	/bin/rm -f $(OUT)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmesas <mesaskevin@live.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/08/03 17:42:22 by kmesas            #+#    #+#              #
#    Updated: 2013/08/03 18:36:29 by kmesas           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = colle-00
FLAG = -Wall -Wextra -Werror
LIB = -L. -lft

all: $(NAME)

$(NAME):
	gcc -o $(NAME) colle-00.c main.c $(LIB) $(FLAG)
	gcc -o colle-01 colle-01.c main.c $(LIB) $(FLAG)
	gcc -o colle-02 colle-02.c main.c $(LIB) $(FLAG)
	gcc -o colle-03 colle-03.c main.c $(LIB) $(FLAG)
	gcc -o colle-04 colle-04.c main.c $(LIB) $(FLAG)

clean:
	rm -f $(NAME) colle-01 colle-02 colle-03 colle-04

fclean: clean

re: fclean all

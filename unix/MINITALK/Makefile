#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scadoux <scadoux@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/08 05:12:02 by scadoux           #+#    #+#              #
#    Updated: 2014/02/08 05:53:47 by scadoux          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME1 = server
NAME2 = client

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC1 = server.c
SRC2 = client.c

OBJECT1 = $(SRC1:.c=.o)
OBJECT2 = $(SRC2:.c=.o)

all: $(NAME1) $(NAME2)

$(NAME1): $(OBJECT1)
	@make -C libft/
	$(CC) -o $(NAME1) $(SRC1) $(CFLAGS) -I -libft/includes/ -L libft/ -lft

$(NAME2): $(OBJECT2)
	@make -C libft/
	$(CC) -o $(NAME2) $(SRC2) $(CFLAGS) -I -libft/includes/ -L libft/ -lft

clean:
	@make -C libft/ clean
	@/bin/rm -f $(OBJECT1)
	@/bin/rm -f $(OBJECT2)


fclean: clean
	@make -C libft/ fclean
	@/bin/rm -f $(NAME1)
	@/bin/rm -f $(NAME2)

re: fclean all

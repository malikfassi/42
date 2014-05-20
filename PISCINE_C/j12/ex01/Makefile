# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfassi-f <malikfassifihri@gmail.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/08/01 04:05:44 by mfassi-f          #+#    #+#              #
#    Updated: 2013/08/01 05:31:13 by mfassi-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_cat

SRC = ./$(NAME).c

OUTPUT = ./$(NAME).o

SRCH = $(NAME).h

all: $(NAME)

$(NAME):
	gcc -Wall -Werror -Wextra -I ./  $(SRCH) $(SRC) -o $(NAME) 	

clean:
	rm -f $(OUTPUT)

fclean: clean
	rm -f $(NAME)

re: fclean all

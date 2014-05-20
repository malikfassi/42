# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfassi-f <malikfassifihri@gmail.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/08/01 04:05:44 by mfassi-f          #+#    #+#              #
#    Updated: 2013/08/01 14:18:20 by mfassi-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_tail

SRC = ./$(NAME).c ./is_numeric.c ./errors.c ./to_int.c

OUTPUT = ./$(NAME).o ./is_numeric.o ./errors.o ./to_int.o

SRCH = ./$(NAME).h

all: $(NAME)

$(NAME):
	gcc -Wall -Werror -Wextra $(SRCH) $(SRC) -o $(NAME) 	

clean:
	rm -f $(OUTPUT)

fclean: clean
	rm -f $(NAME)

re: fclean all

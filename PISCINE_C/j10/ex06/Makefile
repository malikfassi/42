# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfassi-f <malikfassifihri@gmail.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/07/30 21:38:32 by mfassi-f          #+#    #+#              #
#    Updated: 2013/07/30 22:54:26 by mfassi-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = do-op

SRC = ./errors.c ./ft_print.c ./main.c ./operations.c ./to_int.c

OUTPUT = ./errors.o ./ft_print.o ./main.o ./operations.o ./to_int.o

DIRH = ./includes

all: $(NAME)

$(NAME):
	gcc -Wall -Werror -Wextra -c -I$(DIRH) $(SRC) 
	gcc $(OUTPUT) -o $(NAME)

clean:
	rm -f $(OUTPUT)

fclean: clean
	rm -f $(NAME)

re: fclean all


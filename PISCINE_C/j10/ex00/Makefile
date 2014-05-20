# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfassi-f <malikfassifihri@gmail.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/07/29 16:01:31 by mfassi-f          #+#    #+#              #
#    Updated: 2013/07/30 22:22:43 by mfassi-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ./srcs/ft_putchar.c ./srcs/ft_putstr.c ./srcs/ft_strcmp.c \
	   ./srcs/ft_strlen.c ./srcs/ft_swap.c

OUTPUT = ./ft_putchar.o ./ft_putstr.o ./ft_strcmp.o \
	   ./ft_strlen.o ./ft_swap.o

DIRH = ./includes

all: $(NAME)

$(NAME):
	gcc -c -I$(DIRH) $(SRC)
	ar rc libft.a $(OUTPUT)

clean:
	rm -f $(OUTPUT)

fclean: clean
	rm -f $(NAME)

re: fclean all

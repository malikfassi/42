# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfassi-f <malikfassifihri@gmail.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/08/01 04:05:44 by mfassi-f          #+#    #+#              #
#    Updated: 2013/08/01 07:17:03 by mfassi-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_display_file

SRC = ./ft_display_file.c

OUTPUT = ./ft_display_file.o

SRCH = ft_display_file.h

all: $(NAME)

$(NAME):
	gcc -Wall -Werror -Wextra -I ./  $(SRCH) $(SRC) -o $(NAME) 	

clean:
	rm -f $(OUTPUT)

fclean: clean
	rm -f $(NAME)

re: fclean all

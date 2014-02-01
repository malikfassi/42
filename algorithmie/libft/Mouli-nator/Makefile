# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fberot-a lmezard fcorre jlejeune           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/26 08:16:35 by fberot-a          #+#    #+#              #
#    Updated: 2013/11/26 08:26:00 by fberot-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Moulinette

all: $(NAME)

$(NAME):
	@gcc -fPIC -Wall -Werror -Wextra -c ../*.c
	@gcc -fPIC -Werror -Wall -Wextra -shared -o libft.so *.o
	./Mouli-nator

clean:
	@rm -rf *.o
	@rm -rf libft.so

re: clean all


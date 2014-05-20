# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ocosquer <ocosquer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/14 01:00:27 by ocosquer          #+#    #+#              #
#    Updated: 2013/12/15 20:21:04 by ocosquer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = hotrace
HEADER_PATH = ./includes/
SRC_PATH = ./src/
SRC_FILES = ft_memmove.c ft_strlen.c ft_strnew.c \
			ft_strjoin.c ft_strdup.c ft_strchr.c \
			ft_strdel.c ft_memdel.c ft_strclr.c \
			get_next_line.c hotrace.c ft_bzero.c \
			ft_strsub.c ft_data.c ft_putstr.c \
			ft_putchar.c ft_sizetree.c ft_lextree2.c \
			ft_strcpy.c ft_strncat.c ft_strncpy.c \
			ft_lextree.c ft_max.c ft_strcmp.c \
			ft_lexlist.c
OPTI = -O4
BASE_FILES = $(addprefix $(SRC_PATH),$(SRC_FILES))
SRC = $(BASE_FILES)

all: ${NAME}

${NAME}:
	@echo compilation of $(NAME)
	@gcc $(OPTI) -I$(HEADER_PATH) -Wall -Werror -Wextra $(SRC) -o $(NAME)
	@echo Compilation done!

clean:
	@echo Delete .o files
	@rm -f $(SRC_FILES:.c=.o)
	@echo Delete $(NAME)
	@rm -f $(NAME)
	@echo Delete done!

fclean: clean

re: fclean all

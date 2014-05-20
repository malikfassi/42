# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/21 21:34:01 by mfassi-f          #+#    #+#              #
#    Updated: 2013/12/31 16:08:29 by mfassi-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

HPATH = -Iincludes

FLAGS = -Wall -Wextra -Werror -g

SRC_PATH = ./src/

SRC_FILES = ft_memalloc.c 
SRC_FILES += ft_putchar_fd.c
SRC_FILES += ft_putendl_fd.c
SRC_FILES += ft_pipex.c
SRC_FILES += ft_putstr_fd.c
SRC_FILES += pipex.c 
SRC_FILES += ft_strcat.c
SRC_FILES += ft_strcmp.c
SRC_FILES += ft_strdel.c
SRC_FILES += ft_strjoin.c
SRC_FILES += ft_strlen.c 
SRC_FILES += ft_strncat.c 
SRC_FILES += ft_strncmp.c
SRC_FILES += ft_strnew.c
SRC_FILES += ft_strsplit.c
SRC_FILES += ft_strsub.c
SRC_FILES += ft_toupper.c
SRC_FILES += search_path.c
SRC_FILES += utils.c
SRC_FILES += ft_bzero.c
SRC_FILES += ft_strcpy.c


SRC = $(addprefix $(SRC_PATH), $(SRC_FILES))

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(SRC)
	@echo Compilation of $(NAME)
	@gcc $(FLAGS) $(HPATH) $(SRC) -o $(NAME)
	@echo Compilation done !

clean:
	@echo Deleting .o files
	@rm -f $(OBJ)
	@echo Deleting done !

fclean: clean
	@echo Deleting $(NAME)
	@rm -f $(NAME)
	@echo Deleting done !

re:	fclean all

.PHONY: clean

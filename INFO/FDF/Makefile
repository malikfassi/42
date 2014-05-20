# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/18 14:13:44 by mfassi-f          #+#    #+#              #
#    Updated: 2013/12/20 20:15:32 by mfassi-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

LIBNAME = libft

LIBDIR = ./libft

HPATH = -Ilibft/includes -Iincludes

FLAGS = -Wall -Wextra -Werror

DIR_LIBS = /usr/X11/lib

LIBFT = ./libft/libft.a

LIB_FLAGS += -L$(DIR_LIBS) -lXext -lX11 -lmlx

SRC_PATH = ./src/

SRC_FILES = fdf.c vector.c mlxOp.c get_next_line.c ft_math.c parse.c

BASE_FILES = $(addprefix  $(SRC_PATH), $(SRC_FILES))

SRC = $(BASE_FILES)

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME) :
	@echo Compilation of $(LIBNAME)
	make re -C $(LIBDIR)	
	@echo Compilation of $(NAME)
	gcc -g $^ $(FLAGS) $(HPATH) $(LIB_FLAGS) $(SRC) $(LIBFT) -o $(NAME)
	@echo Compilation done !

clean:
	@echo Deleting .o files
	rm -f $(OBJ)
	@echo Deleting done !

fclean : clean
	@echo Deleting $(NAME)
	rm -f $(NAME)
	@echo Deleting done !

re : fclean all

.PHONY: clean fclean re all

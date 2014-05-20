# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/21 21:34:01 by mfassi-f          #+#    #+#              #
#    Updated: 2014/01/10 21:42:49 by mfassi-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GRN = "\x1b[32;01m"

YLLW = "\x1b[33;01m"

NOCOLOR = "\x1b[0m"

NAME = ft_select

LIBFT_NAME = libft.a

LIBFT_DIR = libft

HPATH = -Iincludes -I$(LIBFT_DIR)/includes

LIBFT = $(LIBFT_DIR)/$(LIBFT_NAME)

LIB = -L /usr/bin -ltermcap

FLAGS = -Wall -Wextra -Werror

SRC_PATH = ./src/

SRC_FILES = main.c double_circ_list.c display.c go.c keys.c outc.c \
			select.c utils.c terminal.c

SRC = $(addprefix $(SRC_PATH), $(SRC_FILES))

OBJ = $(SRC:.c=.o)

all: compile_lib $(NAME)

compile_lib:
	@make -C $(LIBFT_DIR)

$(NAME): $(SRC)
	@echo $(GRN)$(NAME)$(NOCOLOR)$(YLLW)[all]$(NOCOLOR): Compilation of $(NAME)
	@gcc $(FLAGS) $(LIB) $(HPATH) $(SRC) $(LIBFT) -o $(NAME)
	@echo $(GRN)$(NAME)$(NOCOLOR)$(YLLW)[all]$(NOCOLOR): Compilation done !

clean:
	@make clean -C $(LIBFT_DIR)
	@echo $(GRN)$(NAME)$(NOCOLOR)$(YLLW)[clean]$(NOCOLOR) : Deleting .o files
	@rm -f $(OBJ)
	@echo $(GRN)$(NAME)$(NOCOLOR)$(YLLW)[clean]$(NOCOLOR) : Deleting done !

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	@echo $(GRN)$(NAME)$(NOCOLOR)$(YLLW)[fclean]$(NOCOLOR) : Deleting $(NAME)
	@rm -f $(NAME)
	@echo $(GRN)$(NAME)$(NOCOLOR)$(YLLW)[fclean]$(NOCOLOR) : Deleting done !

re:	fclean all
	@make re -C $(LIBFT_DIR)

.PHONY: clean

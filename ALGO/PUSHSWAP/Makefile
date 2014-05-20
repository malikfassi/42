# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/22 14:32:09 by mfassi-f          #+#    #+#              #
#    Updated: 2014/05/18 22:44:04 by mfassi-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GRN = "\x1b[32;01m"

YLLW = "\x1b[33;01m"

NOCLR = "\x1b[0m"

NAME = push_swap

FLAGS = -Wextra -Wall -Werror
SRC_PATH    =   ./src/
SRC_FILES   =   push_swap.c intlist.c intlist2.c parse.c

SRC         =   $(addprefix $(SRC_PATH), $(SRC_FILES))

LIB = libft/libft.a

INCLUDES = -I libft/includes -I includes

OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	@echo               Compiling $<
	@gcc $(FLAGS) $(INCLUDES) -c $< -o $@

$(NAME) : $(OBJ)
	@make -C libft
	@echo $(GRN)$(NAME)$(NOCLR)$(YLLW)[all]$(NOCLR) : Compilation of $(NAME)
	@gcc $(FLAGS) $(OBJ) $(LIB) -o $(NAME)

clean :
	@echo $(GRN)$(NAME)$(NOCLR)$(YLLW)[clean]$(NOCLR) : Deleting .o files
	@rm -f $(OBJ)
	@echo $(GRN)$(NAME)$(NOCLR)$(YLLW)[clean]$(NOCLR) : Deleting done !

fclean : clean
	@echo $(GRN)$(NAME)$(NOCLR)$(YLLW)[fclean]$(NOCLR) : Deleting $(NAME)
	@rm -f $(NAME)
	@echo $(GRN)$(NAME)$(NOCLR)$(YLLW)[fclean]$(NOCLR) : Deleting done !

re : fclean all

.PHONY: clean fclean re all
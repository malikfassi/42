# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/22 14:32:09 by mfassi-f          #+#    #+#              #
#    Updated: 2014/05/04 20:23:10 by mfassi-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GRN = "\x1b[32;01m"

YLLW = "\x1b[33;01m"

NOCLR = "\x1b[0m"

NAME = libftprintf.a

FLAGS = -Wextra -Wall -Werror

CC = gcc

AR = ar rc

SRC = ft_printf.c ft_strlen.c ft_putstr.c ft_putchar.c ft_intlen.c ft_putnbr.c\
	  ft_putnbr_fd.c ft_printf_hex.c ft_printf_nbrld.c ft_printf_divers.c \
	  ft_toupper.c ft_printf_long.c

RM = rm -f

OBJ = $(SRC:.c=.o)

all: $(NAME)


%.o: %.c includes/libftprintf.h
	@echo               Compiling $<
	@gcc $(FLAGS) -I includes -c $< -o $@
$(NAME) : $(OBJ)
	@echo $(GRN)$(NAME)$(NOCLR)$(YLLW)[all]$(NOCLR) : Compilation of $(NAME)
	@echo $(GRN)$(NAME)$(NOCLR)$(YLLW)[all]$(NOCLR) : Creating Library $(NAME)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

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

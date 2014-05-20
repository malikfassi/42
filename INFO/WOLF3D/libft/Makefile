# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/22 14:32:09 by mfassi-f          #+#    #+#              #
#    Updated: 2014/01/07 17:29:56 by mfassi-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN = "\x1b[32;01m"

YELLOW = "\x1b[33;01m"

NO_COLOR = "\x1b[0m"

NAME = libft.a

FLAGS = -Wextra -Wall -Werror

CC = gcc

AR = ar rc

SRC = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memchr.c \
	  ft_memcmp.c ft_strlen.c ft_strcpy.c ft_strdup.c ft_strcat.c \
	  ft_strncpy.c ft_strncat.c ft_strchr.c ft_strrchr.c ft_strstr.c \
	  ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_isdigit.c ft_atoi.c \
	  ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isprint.c ft_toupper.c \
	  ft_tolower.c ft_memmove.c ft_strlcat.c ft_memalloc.c ft_memdel.c \
	  ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c \
	  ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c \
	  ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar.c \
	  ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c \
	  ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c \
	  ft_lstadd.c ft_lstiter.c ft_lstmap.c

RM = rm -f

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME) : $(SRC)
	@echo $(GREEN)$(NAME)$(NO_COLOR)$(YELLOW)[all]$(NO_COLOR) : Compilation of $(NAME)
	@gcc $(FLAGS) -I includes -c $(SRC)
	@echo $(GREEN)$(NAME)$(NO_COLOR)$(YELLOW)[all]$(NO_COLOR) : Creation of Library $(NAME)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean : 
	@echo $(GREEN)$(NAME)$(NO_COLOR)$(YELLOW)[clean]$(NO_COLOR) : Deleting .o files
	@rm -f $(OBJ)
	@echo $(GREEN)$(NAME)$(NO_COLOR)$(YELLOW)[clean]$(NO_COLOR) : Deleting done !

fclean : clean 
	@echo $(GREEN)$(NAME)$(NO_COLOR)$(YELLOW)[fclean]$(NO_COLOR) : Deleting $(NAME)
	@rm -f $(NAME)
	@echo $(GREEN)$(NAME)$(NO_COLOR)$(YELLOW)[fclean]$(NO_COLOR) : Deleting done !

re : fclean all

.PHONY: clean fclean re all

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/21 21:34:01 by mfassi-f          #+#    #+#              #
#    Updated: 2014/01/17 14:33:44 by mfassi-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	ft_minishell1

LIB_NAME	=	libft

LIB_DIR		=	./$(LIB_NAME)

HPATH		=	-I$(LIB_DIR)/includes -Iincludes

FLAGS		=	-Wall -Wextra -Werror -g

LIBFT		=	$(LIB_DIR)/$(LIB_NAME).a

SRC_PATH	=	./src/

SRC_FILES	=	get_line.c main.c get_next_line.c free_arr.c search_path.c \
				ft_env.c ft_cd1.c ft_cd2.c utils.c ft_setenv.c ft_unsetenv.c

SRC			=	$(addprefix	$(SRC_PATH), $(SRC_FILES))

OBJ			=	$(SRC:.c=.o)



all			:	$(NAME)


$(NAME)		: $(SRC)
	@make -C $(LIB_DIR)
	@echo Compilation of $(NAME)
	@gcc $(FLAGS) $(HPATH) $(SRC) $(LIBFT) -o $(NAME)
	@echo Compilation done !

clean		:
	@echo Deleting .o files
	@rm -f $(OBJ)
	@echo Deleting done !

fclean		:	clean
	@echo Deleting $(NAME)
	@rm -f $(NAME)
	@echo Deleting done !

re			:	fclean all

.PHONY: clean fclean re all



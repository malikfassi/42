# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/03/26 21:32:32 by mfassi-f          #+#    #+#              #
#    Updated: 2014/03/27 20:57:34 by gchateau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# MAKEFILE UI BY gfanton

NAME = 42sh

CC = gcc
CFLAGS = -Wall -Werror -Wextra -O0 -g3 #-pedantic
CINCS = -I libs/libft/includes -I./includes
CLIBS = -L libs/libft/ -lft -ltermcap

LIB = libs/libft/libft.a

SRCPATH = ./src/

FILES = main.c ft_findexe.c ft_error.c ft_signal.c ft_response.c ft_magic.c \
		ft_getterm.c ft_getdatas.c ft_getdatas_setenv.c ft_getdatas_setlocal.c \
		ft_cd.c ft_cd_set.c ft_cd_check.c ft_cd_putpath.c ft_cd_update.c \
		ft_env.c ft_env_exec.c ft_env_exit.c ft_env_setav.c ft_env_setep.c \
		ft_env_print.c \
		implemented_function.c \
		ft_getenv.c ft_getlocal.c ft_getvar.c ft_setvar.c ft_delvar.c \
		ft_setenv.c ft_unsetenv.c ft_exit.c ft_color.c ft_echo.c ft_set.c \
		ft_unset.c ft_export.c \
		ft_history.c \
		ft_cmdsplit.c ft_cmdtrim.c \
		ft_check_daccess.c ft_check_path.c \
		ft_putpath.c ft_tputs.c ft_prompt_autocomplete.c \
		ft_shell_start.c ft_shell_end.c ft_shell_reload.c \
		ft_prompt.c ft_prompt_readentry.c ft_prompt_readkey.c \
		ft_prompt_return.c \
		ft_prompt_ctrld.c ft_prompt_clear.c ft_prompt_print.c \
		ft_prompt_reprint.c \
		ft_prompt_addchar.c ft_prompt_delchar.c ft_prompt_nl.c \
		ft_prompt_ctrlr.c \
		ft_move_left.c ft_move_right.c ft_move_up.c ft_move_down.c \
		ft_move_home.c ft_move_end.c ft_move_prev.c ft_move_next.c \
		ft_history_add.c ft_history_del.c ft_history_prepare.c \
		ft_history_new.c \
		ft_history_prev.c ft_history_next.c \
		ft_pipe.c \
		parser.c parser2.c execution.c cmds.c t_env.c parser_utils.c \
		ft_redir.c \
		lx_lexer.c lx_tools.c lx_quote.c lx_token.c files_redir.c utils.c \
		parse_var.c

SRC = $(addprefix $(SRCPATH), $(FILES))
OBJ = $(SRC:.c=.o)

FLAG = 0
V = 0
SKIP_1 :=
SKIP_0 := \033[A
SKIP = $(SKIP_$(V))
C = \033[0;33m
U = $(C)[$(NAME)]----->\033[0m

.PHONY: all, clean, fclean, re, .msgcompile

all: coffee $(NAME)

coffee:
	@echo ""
	@echo "ENJOY A GOOD COFFEE WHILE COMPILING:"
	@echo ""
	@echo "     )))  (((     "
	@echo "    (((  )))      "
	@echo "     )))  (((     "
	@echo "  ______________  "
	@echo "  \            /_ "
	@echo "   \          /  |"
	@echo "    \        /--- "
	@echo "   ------------   "
	@echo ""

$(NAME): $(LIB) $(OBJ)

	@echo "$(U)$(C)[BUILD]\033[0;32m"
	@$(CC) -o $@ $(OBJ) $(CFLAGS) $(CINCS) $(CLIBS)
	@echo "$(SKIP)\033[2K$(SKIP)\033[2K"
	@echo "$(SKIP)$(U)$(C)[BUILD  :\033[1;32m DONE$(C)]\033[0m"

%.o: %.c
	@echo "$(U)$(C)[COMPILE: \033[1;31m$<\033[A\033[0m"
	@echo "\033[0;32m"
	@$(CC) -o $@ $(CFLAGS) $(CINCS) -c $<
	@echo "\033[1;31m [.working.]]"
	@echo "$(SKIP)\033[2K\033[A\033[2K$(SKIP)"

$(LIB):
	@make -C libs/libft/

clean:
	@echo "[\033[1;33mCLEANING 42SH\033[0m]"
	@make -C libs/libft/ clean
	@rm -rf $(OBJ)

fclean:
	@echo "[\033[1;31mREMOVING 42SH\033[0m]"
	@make -C libs/libft/ fclean
	@rm -rf $(OBJ)
	@rm -rf $(NAME)

re: fclean all

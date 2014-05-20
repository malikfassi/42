#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/22 15:37:16 by gchateau          #+#    #+#              #
#    Updated: 2014/03/24 20:25:02 by mfassi-f         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a

FILES = ft_atoi.c ft_itoa.c ft_intlen.c ft_tolower.c ft_toupper.c ft_bzero.c \
		ft_fibonacci.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
		ft_isdigit.c ft_isprint.c ft_isspace.c \
		ft_isupper.c ft_islower.c \
		ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memset.c \
		ft_memalloc.c ft_memdel.c \
		ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c \
		ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c \
		ft_strcat.c ft_strchr.c ft_strcmp.c ft_strccmp.c ft_strcpy.c ft_strdup.c \
		ft_strichr.c ft_strrichr.c ft_strlcat.c ft_strlen.c ft_strncat.c ft_strncmp.c \
		ft_strncpy.c ft_strnstr.c ft_strrchr.c ft_strstr.c ft_strclr.c ft_strsub.c \
		ft_strequ.c ft_strnequ.c ft_strnew.c ft_strdel.c ft_strfjoin.c ft_strjoin.c \
		ft_strtrim.c ft_strsplit.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c \
		ft_strtolower.c ft_strtoupper.c \
		ft_lstnew.c ft_lstadd.c ft_lstadd_end.c ft_lstiter.c ft_lstdelone.c ft_lstdel.c \
		ft_lstlen.c ft_lstmap.c \
		ft_clstadd_after.c ft_clstadd_before.c ft_clstdel.c ft_clstdelone.c \
		ft_clstiter.c ft_clstlen.c ft_clstnew.c \
		ft_dlstadd_after.c ft_dlstadd_before.c ft_dlstadd_end.c ft_dlstadd_first.c \
		ft_dlstdel.c ft_dlstdel_fwd.c ft_dlstdel_rwd.c ft_dlstdelone.c \
		ft_dlstiter.c ft_dlstiter_fwd.c ft_dlstiter_rwd.c ft_dlstnew.c \
		ft_dlstlen.c ft_dlstlen_fwd.c ft_dlstlen_rwd.c \
		ft_arrsize.c ft_arrnew.c ft_arradd.c ft_arrdup.c ft_arrdel.c ft_arrfree.c \
		ft_arridel.c ft_arriter.c ft_arriteri.c \
		ft_realpath.c ft_implode.c ft_explode.c get_next_line.c

GRN = "\x1b[32;01m"
YLLW = "\x1b[33;01m"
NCLR = "\x1b[0m"
RM = rm -f
SRC = $(FILES)
OBJ = $(SRC:.c=.o)
LIBNAME = $(NAME).a

all: $(NAME)

$(NAME) : $(SRC)
	@echo $(GRN)$(NAME)$(NCLR)$(YLLW)[all]$(NCLR):'\t''\t'Creation of $(NAME)
	@gcc $(FLAGS) -I includes -c $(SRC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean :
	@echo $(GRN)$(NAME)$(NCLR)$(YLLW)[clean]$(NCLR): '\t'Deleting \'.o\' files
	@rm -f $(OBJ)

fclean : clean
	@echo $(GRN)$(NAME)$(NCLR)$(YLLW)[fclean]$(NCLR):'\t'Deleting $(NAME)
	@rm -f $(NAME)

re : fclean all

.PHONY: clean fclean re all

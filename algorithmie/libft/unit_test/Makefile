.PHONY: all, clean, fclean, re

NAME = unit_test
CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -O3 -I./..
LDFLAGS = -L./.. -lft
SOURCE = main.c unit_test.c
OBJ = $(SOURCE:.c=.o)

all : $(NAME)


$(NAME): $(OBJ) ../libft.a
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

../libft.a:
	@make -C ..

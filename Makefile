NAME = fillit

SRC = main.c input_read.c creat_tetrimino.c solve.c ft_bzero.c ft_strsplit.c ft_putchar.c ft_putstr.c ft_strlen.c ft_memdel.c ft_memset.c ft_putstr_fd.c ft_wordcount.c ft_wordlen.c

OBJ = $(SRC:.c=.o)

CC = gcc

CFLAGS = -Wall - Wextra -Werror

SRCDIR = ./srcs/

all: $(NAME)

%.o:$(SRCDIR)%.c
	$(cc) $(CFLAGS) -o $@ -c #<

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean:
	rm - rf $(OBJ)

fclean: clean
	rm - rf $(NAME)

re: fclean all

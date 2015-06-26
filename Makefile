NAME = fractol
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC += src/buddhabrot.c
SRC += src/julia.c
SRC += src/main.c
SRC += src/mandelbrot.c
SRC += src/mlx.c

OBJ = $(SRC:%.c=%.o)
LIB = libft/libft.a

all: $(LIB) $(NAME)

$(NAME): $(OBJ)
	@echo "Building $@"
	@$(CC) -O3 $(CFLAGS) -L libft/ -lft -L/usr/X11/lib -lmlx -lXext -lX11 -o $(NAME) $(OBJ)

%.o: %.c
	@echo "Building $@"
	@$(CC) $(CFLAGS) -I. -o $@ -c $^

clean:
	rm -f $(OBJ)
	make -C libft/ clean

fclean: clean
	make -C libft/ fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

$(LIB): lib

lib:
	@make -C libft/

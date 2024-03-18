CFLAGS = -Wall -Werror -Wextra

NAME = fractol

CC = gcc

SRC = main.c string_utils.c events.c init.c math_utils.c render.c fractol.h

OBJS = $(SRC:.c=.o)

MLX = -lmlx OpenGL AppKit


all : $(NAME)

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(MLX) -o $(NAME)

clean :
	@rm -rf $(OBJS)

fclean : clean
	@rm -rf $(NAME)

re : fclean all

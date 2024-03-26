GREEN = \033[0;32m

NAME 	=	fractol

OBJ	=	$(SRC:.c=.o)

NAMELIB	=	libftfractol.a

LIB 	=	libft/libft.a

LINK 	=	-lmlx  -framework OpenGL -framework AppKit -L ./minilibx_opengl_20191021

SRC		=	fractol.c fractol_utils.c mandelbrot.c inits.c color.c \
			render.c julia.c events.c 
CC	=	gcc

CFLAGS	=	-Wall -Werror -Wextra

COMP	=	$(CC) $(CFLAGS) $(LIB) $(LINK)

RM		=	rm -f

all:	$(NAME)

$(NAME):	$(OBJ) Makefile fractol.h $(LIB) libft/libft.h
	@$(MAKE) -C ./libft
	@$(COMP) $(OBJ) -o $(NAME)
	@echo "$(GREEN)Fractol Compiled Successfully$(RESET)"

clean:
	@$(RM) $(OBJ)
	@$(MAKE) fclean -C ./libft
	@echo "Cleaned fractol"

fclean:	clean
	@$(RM) $(NAME)
	@$(MAKE) fclean -C ./libft
	@echo "Fractol was removed"

re:			fclean all

#FANCY
RESET = \033[0m
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
MAGENTA = \033[35m
CYAN = \033[36m
WHITE = \033[37m
BOLD = \033[1m
SILENCE = --no-print-directory

#PROG NAME
NAME = fractol
ARCHIVE = fractol.a
# COMPILER
CC		= gcc
FLAGS	= -Werror -Wextra -Wall -MMD -g
MAKE_LIB = ar -rcs
LIB = -L. -lmlx -framework OpenGL -framework AppKit

#Minilibx
MLX_PATH	= minilibx_opengl_20191021/
MLX_NAME	= libmlx.a
MLX			= $(MLX_PATH)$(MLX_NAME)

#libft
LIBFT_NAME	= libft.a
LIBFT		= $(LIBFT_PATH)$(LIBFT_NAME)

#includes
INCLUDES	= ./minilibx_opengl_20191021/mlx.h keys.h ./libft/libft.h fractol.h

#sources
SRCS			=	fractol.c \
				init.c \
				fractal_utils.c \
				events.c \
				render.c \
				color.c \
				passing_args.c\
				help_msg.c \
				fractals/mandelbrot.c \
				fractals/julia.c \
				fractals/burning_ship.c \
				colors_schemes/color_interpolated.c \
				colors_schemes/color_special.c \
				colors_schemes/color_striped.c

#Objects
OBJS		= $(SRCS:.c=.o)
DEPS		= $(SRCS:.c=.d)
SILENCE = --no-print-directory

all: $(NAME)

$(NAME) : $(OBJS) $(DEPS) $(ARCHIVE) fractol.h keys.h Makefile ./libft/libft.h 
	@echo "$(YELLOW) Compiling $(NAME) $(RESET)"
	@make -C ./minilibx_opengl_20191021/ all
	@cp ./minilibx_opengl_20191021/libmlx.a .
	@make -C ./libft all $(SILENCE)
	@cp ./libft/libft.a .
	@$(CC) -o $(NAME) $(ARCHIVE) libft.a $(LIB)
	@echo "$(YELLOW) Fractol created succesfully$(RESET)"

$(ARCHIVE) : $(OBJS)
	@$(MAKE_LIB) $(ARCHIVE) $^

%.o : %.c
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@echo "$(YELLOW) Cleaning... $(RESET)"
	@make -C ./minilibx_opengl_20191021/ clean
	@make -C ./libft clean
	@rm -f $(OBJS) $(DEPS) libmlx.a libft.a fractol.a
	@echo "$(YELLOW) clean DONE  $(RESET)"

fclean: clean
	@echo "$(YELLOW) FCleaning ... $(RESET)"
	@make -C ./minilibx_opengl_20191021 clean
	@make -C ./libft fclean
	@rm -f $(NAME) $(DEPS) libmlx.a libft.a fractol.a
	@echo "$(GREEN) FCleaning DONE  $(RESET)"

re: fclean all

.PHONY: all clean fclean re 

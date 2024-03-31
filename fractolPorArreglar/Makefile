GREEN = \033[32m
WHITE = \033[37m

NAME = fractol
ARCHIVE = fractol.a
SRCS = fractol.c \
       color.c \
       events.c \
       fractol_utils.c \
       init.c \
       mandelbrot.c \
       julia.c \
       render.c \
	   color_interpolated.c \
	   color_striped.c \
 
OBJS = $(SRCS:.c=.o)
INCLUD = ./minilibx_opengl_20191021/mlx.h \ ./libft/libft.h
CC = gcc
MAKE_LIB = ar -rcs
FLAGS = -Wall -Wextra -Werror -MMD -g
LIB = -L. -lmlx -framework OpenGL -framework AppKit
DEPS = $(SRCS:.c=.d)
SILENCE = --no-print-directory

all: $(NAME)

$(NAME) : $(ARCHIVE) fractol.h Makefile ./libft/libft.h
	@echo "$(WHITE) $(NAME) $(RESET) $(GREEN) ok $(RESET)"
	@echo "\n${GREEN} Minilibx compilando: $(DEF_COLOR)\n"
	@make -C ./minilibx_opengl_20191021 all
	@cp ./minilibx_opengl_20191021/libmlx.a .
	@make -C ./libft all $(SILENCE)
	@cp ./libft/libft.a .
	@$(CC) -o $(NAME) $(ARCHIVE) libft.a $(LIB)

$(ARCHIVE) : $(OBJS)
	@$(MAKE_LIB) $(ARCHIVE) $^

%.o	:	%.c
	@$(CC) $(FLAGS) -c $< -o $@
	@echo "$(GREEN) ok $(RESET) $(CYAN)$(BOLD) $<$(RESET)"

clean:
	@echo "$(MAGENTA) Eliminando .o  ... $(RESET)"
	@make -C ./minilibx_opengl_20191021 clean
	@make -C ./libft clean
	@rm -f $(OBJS) $(DEPS) libmlx.a libft.a
	@echo "$(GREEN) cleaning DONE  $(RESET)"

fclean: clean
	@rm -f fractol.a $(NAME)
	@echo "$(GREEN) fclean OK  $(RESET)"

re: fclean all

.PHONY: all clean fclean re 

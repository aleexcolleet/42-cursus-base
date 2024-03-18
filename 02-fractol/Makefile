NAME = fractol
OS = $(shell uname)

# directories
SRCDIR = ./src
INCDIR = ./includes
OBJDIR = ./obj

# src / obj files
SRC = main.c \
      init.c \
      events.c \
      math_utils.c \
      render.c \
      string_utils.c \

OBJ = $(addprefix $(OBJDIR)/,$(SRC:.c=.o))

# compiler
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

# mlx library
MLX = ./miniLibX/
MLX_LNK = -L $(MLX) -l mlx -framework OpenGL -framework AppKit
MLX_INC = -I $(MLX)

all: obj $(NAME)

obj:
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) $(MLX_INC) -I $(INCDIR) -o $@ -c $<

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(MLX_LNK) -lm -o $(NAME)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

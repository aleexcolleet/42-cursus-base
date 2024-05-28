GREEN = \033[0;92m
DEF_COLOR = \033[0m

NOM = libmlx.a
SRC = mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
SRC += mlx_png.c mlx_mouse.m
OBJ1 = $(SRC:.c=.o)
OBJ = $(OBJ1:.m=.o)
CFLAGS += -O2 -Wno-deprecated
CFLAGS += -DSTRINGPUTX11

all: $(NOM)

$(NOM): $(OBJ)
	@ar -r $(NOM) $(OBJ)
	@ranlib $(NOM)
	@echo "\n${GREEN}Created ${NOM} ✓${DEF_COLOR}\n"

clean:
	@rm -f $(NOM) $(OBJ) *~
	@rm -f mlx_app

re: clean all

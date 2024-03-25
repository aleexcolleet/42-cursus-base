#ifndef FRACTOL_H
# define FRACTOL_H

//main DEFINES
# define MAX_ITERATION 25
# define MANDELBROT 1
# define JULIA 2
//MLBX
# include "./libft/libft.h"
# include  "./minilibx_opengl_20191021/mlx.h"

//DEFAULTS
# define WIDTH 1250
# define HEIGHT 1250

# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include <math.h>

//EVENTS
enum {
	W = 13,
	A = 0,
	S = 1,
	D = 2,
	UP_ARROW = 126,
	DOWN_ARROW = 125,
	LEFT_ARROW = 123,
	RIGHT_ARROW = 124,
	LEFT_CTRL = 256,
	LEFT_ALT = 261,
	LEFT_SHIFT = 257,
	ESC			= 53,
	ON_DESTROY	= 17,
	ON_MOUSE_DW	= 4,
};

//STRUCTURES
//
//COLORS
typedef struct s_color
{
	int	r;
	int	g;
	int	b;
	int	t;
}	t_color;

//IMAGE
typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		endian;
	int		lineLen;
}	t_img;

typedef struct s_data
{
	void			*mlx_con;
	void			*win_con;
	t_img			*img_data;
	t_color			*color;
	double			min_r;
	double			max_r;
	double			min_i;
	double			max_i;
	unsigned int	count;
	int				color_shift;
	int				resolution_shift;
	int				set;
	double			center_i;
	double			center_r;
	double			julia_shiftx;
	double			julia_shifty;
	char			**args;
}	t_data;	

//PROTOTYPES
//
// INIT
void	set_min_max(t_data *fractol);
void	commands_list(t_data *fractol);
void	win_gen(t_data *fractol);
void	mlx_setup(t_data *fractol);
t_data	init_structure(void);

//COLORS
//
int	get_blue(int color_value);
int	get_green(int color_value);
int	get_red(int	color_value);
void	apply_shift(t_data *fractol);
void	shift_color(t_data *fractol);

//EVENTS
//
void	handle_events(t_data *fractol);
int	handle_keys(int keycode, t_data *fractol);
int	handle_mouse(int mousecode, int x, int y, t_data *fractol);

//FRACT_UTILS
//
void	my_px_put(t_img *img, int x, int y, int color);
void	move(t_data	*f, char direction);
void	mouse_zoom(t_data *f, double zoom, int x, int y);
void	clean_exit(t_data *fractol);

//MISC functions
//
int	ft_is_little_endian(void);

//MANDELBROT
//
void	generate_mandelbrot(t_data *fractol);
int	is_actually_mandel(double yf, double yi, t_data *fractol);

//JULIA
//
void	gen_julia(t_data *f);
int	is_actually_julia(double zr, double zi, t_data *fractol);
void	julia_shift(int x, int y, t_data *f);
//RENDER
//
int	make_color(t_data *fractol);
int	create_trgb(int t, int r, int g, int b);
int	generate_fractal(t_data *fractol);
void	check_which_fractal(t_data *fractol, char *arg);

#endif

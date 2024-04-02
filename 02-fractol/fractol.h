#ifndef FRACTOL_H
# define FRACTOL_H
//FRACTAL SETS

# define MANDELBROT 1
# define JULIA 2
# include "libft/libft.h"
# include "minilibx_opengl_20191021/mlx.h"
# include <stdio.h>
# include <math.h>

# define WIDTH 900
# define HEIGHT 900
# define MAX_ITERATIONS 60

enum
{
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
	MOUSE_WHEEL_UP = 4,
	MOUSE_WHEEL_DOWN = 5,
	MOUSE_BTN = 1
};

typedef struct s_data
{
	void	*mlx_con;
	void	*win_con;
	void	*img;
	char	*buf;
	int		set;
	double	min_r;
	double	max_r;
	double	min_i;
	double	max_i;
	double	kr;
	double	ki;
	double	sx;
	double	rx;
	double	fx;
	int		*palette;
	int		color_pattern;
	int		color;
}	t_data;

//SETS
int	mandelbrot(double cr, double ci);
int	julia(t_data *f, double zr, double zi);

//DRAW FRACTALS
void	render(t_data *f);
int	julia_shift(int x, int y, t_data *f);

//COLORS
void	color_shift(t_data *f);
void	set_color_mono(t_data *f, int color);
void	set_color_multiple(t_data *f, int colors[4], int n);
void	set_color_zebra(t_data *f, int color);
void	set_color_triad(t_data *f, int color);
void	set_color_tetra(t_data *f, int color);

//EVENTS
int	handle_keys(int keycode, t_data *fractol);
int	mouse_event(int keycode, int x, int y, t_data *mlx);

//INITS
void	init_structure(t_data *f);
void	reinit_img(t_data *f);
void	mlx_setup(t_data *f);
void	get_complex_layout(t_data *f);
void	get_color(t_data *f, int ac);
////atof

//UTILS
int	end_fractol(t_data *f);
void	clean_exit(int exit_code, t_data *f);
void	help_msg(t_data *f);
void	commands_list(t_data *fractal);
int	get_percent_color(int color, double percent);

#endif

#ifndef FRACTOL_H
# define FRACTOL_H

# include "./minilibx_opengl_20191021/mlx.h"
# include "./libft/libft.h"
# include "keys.h"
# include <stdio.h>
# include <math.h>

/*  Dimensions	*/
# define WIDTH 900
# define HEIGHT 900
# define MAX_ITERATIONS 60

/*  Fractal sets	*/
# define MANDELBROT 1
# define JULIA 2
# define BURNING_SHIP 3
# define TRICORN 4
# define MANDELBOX 5

typedef struct s_data
{
	void	*mlx;
	void	*win;
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

//FRACTOL
//
//INITS
//
void	init(t_data *f);
void	init_structure(t_data *f);
void	reinit_img(t_data *f);
void	get_complex_layout(t_data *f);
void	clean_init(t_data *f);

void	render(t_data *f);
//COLORS
//
void	color_shift(t_data *f);

//EVENTS
//
int		mouse_event(int keycode, int x, int y, t_data *mlx);
int		key_event(int keycode, t_data *mlx);

//HELP MESS
//
void	help_msg(t_data *f);
void	commands_list(void);
void	print_color_options(void);
void	print_fractal_options(void);

//FRACTOL UTILS & Args
//
double	ft_atof(char *str);
void	get_color(t_data *f, int ac, char **av);
int		end_fractol(t_data *mlx);
void	clean_exit(int exit_code, t_data *f);
int		message(char *str1, char *str2, int errnum);

//Fractols
//
int		julia_shift(int x, int y, t_data *f);
int		burning_ship(double cr, double ci);
int		julia(t_data *f, double zr, double zi);
int		mandelbrot(double cr, double ci);

//COLORS SCHEMES
//
void	set_color_multiple(t_data *f, int colors[4], int n);
void	set_color_mono(t_data *f, int color);
void	set_color_graphic(t_data *f, int color);
void	set_color_contrasted(t_data *f, int color);
void	set_color_opposites(t_data *f, int color);
void	set_color_tetra(t_data *f, int color);
void	set_color_triad(t_data *f, int color);
void	set_color_zebra(t_data *f, int color);
int		get_percent_color(int color, double percent);

#endif

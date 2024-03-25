#include "fractol.h"

void	check_which_fractal(t_data *fractol, char *arg)
{
	if (ft_strncmp(arg, "mandelbrot", 10) == 0)
		fractol->set = MANDELBROT;
	else if (ft_strncmp(arg, "julia", 5) == 0)
		fractol->set = JULIA;
	else
	{
		write(1, "usage: ./fractol <name>\n", 24);
		write(1, "mandelbrot or julia < param 1> < param 2>\n", 42);
		clean_exit(fractol);
	}
	return ;
}

int	generate_fractal(t_data *fractol)
{
	handle_events(fractol);
	if (fractol->set == MANDELBROT)
		generate_mandelbrot(fractol);
	else if (fractol->set == JULIA)
		gen_julia(fractol);
	return (0);
}

//bit shifts the ints into the correct position for color 
//coding.
int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	make_color(t_data *f)
{
	int	color_value;

	color_value = f->count * 15;
	f->color->r = get_red(color_value);
	f->color->g = get_green(color_value);
	f->color->b = get_blue(color_value);
	apply_shift(f);
	return (create_trgb(0, f->color->r, f->color->g, \
			f->color->b));
}

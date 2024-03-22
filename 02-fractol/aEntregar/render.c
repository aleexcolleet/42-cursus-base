#include "fractol.h"

void	check_which_fractal(t_data *fractol, char *arg)
{
	if (ft_strncmp(arg, "mandelbrot", 10) == 0)
		fractol->set = MANDELBROT;
	else
		fractol->set = JULIA;
	return ;
}

int	generate_fractal(t_data *fractol)
{
	handle_events(fractol);
	if (fractol->set == MANDELBROT)
		generate_mandelbrot(fractol);
	//if (fractol->set == JULIA)
	//	gen_julia(fractol);
	return (0);
}

//bit shifts the ints into the correct position for color 
//coding.
int	create_trgb(int t, int r, int g, int b)
{
	return(t << 24 | r << 16 || g << 8 | b);
}

int	make_color(t_data *fractol)
{
	int	color_value;

	color_value = fractol->count * 15;
	fractol->color->red = get_red(color_value);
	fractol->color->green = get_green(color_value);
	fractol->color->blue = get_blue(color_value);
	apply_shift(fractol);
	return (create_trgb(0, fractol->color->red,
			fractol->color->green,
			fractol->color->blue));
}

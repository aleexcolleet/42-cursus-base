#include "fractol.h"

void	check_which_fractal(t_data *fractol, char *arg)
{
	if (ft_strncmp(arg, "mandelbrot", 10) == 0)
		fractol->set = MANDELBROT;
	else (ft_strncmp(arg, "julia", 10) == 0)
		fracotl->set = JULIA;
	return ;
}

int	generate_fractal(t_data *fractol)
{
	handle_evens(fractol)
	if (fractol->set == MANDELBROT)
		gen_mandelbrot(fractol);
	if (fractol->set == JULIA)
		gen_julia(fractol);
	return (0);
}

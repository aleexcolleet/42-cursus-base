#include "fractol.h"
/*
	Julia and Mandelbrot
	infinite zoom
	able to take command line args to disipline
			which fractal render
	able to take command line args to shape Julia, i.e x y coordinates
	esc closes the process with no leaks
	clinks on the x window, closes the process leaks free
*/

// 2 promps
// ./fractol Mandelbrot
// ./frctol julia <real> <i>
//
// the main is like a TLDR(means I need to understand the holw process from main fucnt)

int main(int as, char **av)
{
	t_fractal	fractal;

	if (2 == as && !ft_strncmp(av[1], "mandelbrot", 10)
		|| 4 == as && !ft_strncmp(av[1], "julia", 5))
	{
		fractal_init(&fractal);
		fractal_render(&fractal);
		mlx_loop(fractal.mlx_connection); //loop event like clicking the mouse...
	}
	else
	{
		putstr_fd(ERROR_MES, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}


}

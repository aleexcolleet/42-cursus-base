# include "fractol.h"

int	julia_shift(int x, int y, t_data *f)
{
	f->kr = f->min_r + (double)x * (f->max_r - f->min_r) / WIDTH;
	f->ki = f->max_i + (double)y * (f->min_i - f->max_i) / HEIGHT;
	render(f);
	return (0);
}

int	julia(t_data *f, double zr, double zi)
{
	int		n;
	double	tmp;

	n = 0;
	while (n < MAX_ITERATIONS)
	{
		if ((zi * zi + zr * zr) > 4.0)
			break ;
		tmp = 2 * zr * zi + f->ki;
		zr = zr * zr - zi * zi + f->kr;
		zi = tmp;
		n++;
	}
	return (n);
}

/*
* The Julia set is closely related to the Mandelbrot set:
* formula is identical. But the difference is on the complex
* values we add to it.
*
* Julia starts with pixel coordinates as
*	zr and zi and adds another complex number (kr and ki) every time
*	it iterates.
*/

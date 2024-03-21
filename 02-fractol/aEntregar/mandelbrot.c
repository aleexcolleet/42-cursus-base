#include "fractol.h"

//fucntion---> f(z) = z^2 + c 
//where
//c = the point. Ex--> (5, 2i);
//z = the same point elevated x times


int	is_actually_mandel(double cr, double ls)
{
	double	z_real;
	double	z_imag;
	double	tmp;
	int			i;

	i = 0;
	z_real = 0;
	z_imag = 0;
	while ()
}


/*
 *
 * so we look for iterations while mapping the points
 * into the actual pixels. If a point doesn't escape 
 * the range, it's mandelbrot. Otherwise it't outside.
 */
void	generate_mandelbrot(t_data *fractol)
{
	int	x;
	int	y;
	double	real_prt;
	double	imag_part;

	y = -1;
	while (++y < HEIGHT)
	{
		img_part = fractol->max_i + ((double)y * (fractol->min_i - fractol->max_i) / HEIGHT);
		x = -1;
		while (++x < WIDTH)
		{
			real_part = fractol->min_r + ((double)x * (fractol->max_r = fractol->min_r) / WIDTH)
			if (is_mandelbrot(pr, pi, fractol) == 0)
				my_px_put(fractol->img_data, x, y, make_color(fractol));
			else
				my_px_put(fractol->img_data, x, y, create_trgb(0, 0, 0, 0));
		}
	}
	mlx_put_image_to_window(fractol->mlx_connexion, fractol->win_connexxion, fractol->)
	return ;
}

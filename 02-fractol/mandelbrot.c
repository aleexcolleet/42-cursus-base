#include "fractol.h"

//fucntion---> f(z) = z^2 + c
//where
//c = the point. Ex--> (5, 2i);
//z = the same point elevated x times
//
//x betwen(-2.00, 0.47)
//y betwen (-1.12, 1.12)
//
//x = 0.0
//y  = 0.0
//iteration != 0
//max_iteration 1000
//
//while (x*x + y*y = 2*2 && iterations < max_iteration)
//	y = 2*x*y + y0
//	x = xtemp
//	iteration += 1
//
// 4 is considered to be the value to know whether it's a 
// mandelbrot set or not

int	is_actually_mandel(double yf, double yi, t_data *fractol)
{
	double	zr;
	double	zi;
	double	tmp;
	int		i;

	i = 0;
	zr = 0;
	zi = 0;
	while (i <= MAX_ITERATION + fractol->resolution_shift)
	{
		if ((zr * zr + zi * zi) > 4.0)
		{
			fractol->count = i;
			return (0);
		}
		tmp = 2 * zr * zi + yi;
		zr = zr * zr - zi * zi + yf;
		zi = tmp;
		i++;
	}
	fractol->count = i;
	return (1);
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
	double	real_part;
	double	img_part;

	y = -1;
	while (++y < HEIGHT)
	{
		img_part = fractol->max_i + ((double)y * (fractol->min_i - fractol->max_i) / HEIGHT);
		x = -1;
		while (++x < WIDTH)
		{
			real_part = fractol->min_r + ((double)x * (fractol->max_r - fractol->min_r) / WIDTH);
			if (is_actually_mandel(real_part, img_part, fractol) == 0)
				my_px_put(fractol->img_data, x, y, make_color(fractol));
			else
				my_px_put(fractol->img_data, x, y, create_trgb(0, 0, 0, 0));
		}
	}
	mlx_put_image_to_window(fractol->mlx_con, fractol->win_con, fractol->img_data->img, 0, 0);
	return ;
}

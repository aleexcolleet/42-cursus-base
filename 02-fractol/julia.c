#include "fractol.h"

/*
	Julia and Mandelbrot are very related
	Julia set formula
		f(z) = z^n + c
	where c is a constant.

	then:
	while (zx * zx - zy * zy < R**2 && iter < max_iter)
	{
		xtemp = zx * zx - zy * zy;
		zy = 2 * zx * zy + cy;
		zx = xtemp + cx;
	}
*/ 

void	gen_julia(t_data *f)
{
	int		x;
	int		y;
	double	pr;
	double	pi;

	if (!f)
		return ;
	y = -1;
	while (++y < HEIGHT)
	{
		pi = f->max_i + ((double)y * (f->min_i - f->max_i) / HEIGHT);
		x = -1;
		while (++x < WIDTH)
		{
			pr = f->min_r + ((double)x * (f->max_r - f->min_r) / WIDTH);
			if (is_actually_julia(pr, pi, f) == 0)
				my_px_put(f->img_data, x, y, make_color(f));
			else
				my_px_put(f->img_data, x, y, create_trgb(0, 0, 0, 0));
		}
	}
	mlx_put_image_to_window(f->mlx_con, f->win_con, f->img_data->img, 0, 0);
	return ;
}

int	is_actually_julia(double zr, double zi, t_data *fractol)
{
	double	tmp;
	int		i;

	i = 0;
	while (i++ < MAX_ITERATION + fractol->resolution_shift)
	{
		if ((zr * zr + zi * zi) > 4)
		{
			fractol->count = i;
			return (0);
		}
		tmp = zr * zr - zi * zi;
		zi = 2 * zr * zi + fractol->julia_shifty;
		zr = tmp + fractol->julia_shiftx;
	}
		fractol->count = i;
	return (1);
}

void	julia_shift(int x, int y, t_data *f)
{
	f->julia_shiftx = f->min_r + (double)x * (f->max_r - f->min_i) / WIDTH;
	f->julia_shifty = f->max_i + (double)y * (f->min_i - f->max_i) / HEIGHT;
	ft_printf("New Julia Parameters---> x = %d, y = %d\n", x, y);
	return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollet- <acollet-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:42:04 by acollet-          #+#    #+#             */
/*   Updated: 2024/01/12 15:36:26 by acollet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	generate_mandelbrot(t_data *f)
{
	int		x;
	int		y;
	double	real_part;
	double	img_part;

	y = -1;
	while (++y < HEIGHT)
	{
		img_part = f->max_i + ((double)y * (f->min_i - f->max_i) / HEIGHT);
		x = -1;
		while (++x < WIDTH)
		{
			real_part = f->min_r + ((double)x * (f->max_r - f->min_r) / WIDTH);
			if (is_actually_mandel(real_part, img_part, f) == 0)
				my_px_put(f->img_data, x, y, make_color(f));
			else
				my_px_put(f->img_data, x, y, create_trgb(0, 0, 0, 0));
		}
	}
	mlx_put_image_to_window(f->mlx_con, f->win_con, f->img_data->img, 0, 0);
	return ;
}

#include "fractol.h"

//MANDELBROT
//
//z = z2 + c
//

//JULIA
//constant being the input complex value
//z = pixel_point + constant
//
//
//

//Put pixel in my image buffer
static void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int offset;

	offset = (y * img->lineLen) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixPtr + offset) = color;
}

//TOGGLE MANDEL OR JULIA
static void	mandel_or_julia(t_complex *z, t_complex *c, t_fractal *fractal)
{
	if (ft_strncmp(fractal->name, "julia", 5))
	{
		c->x = fractal->julia_x;
		c->y = fractal->julia_y;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
}

static void	handle_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	z.x = (map(x, -2, 2, WIDTH) * fractal->zoom) + fractal->shift_x;
	z.y = (map(y, 2, -2, HEIGHT) * fractal->zoom)+ fractal->shift_y;

	mandel_or_julia(&z, &c, fractal);
	while (i < fractal->iterations_definition)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractal->escape_value)
		{
			color = map(i, BLACK, WHITE, fractal->iterations_definition);
			my_pixel_put(x, y, &fractal->img, color);
			return ;
		}
		++i;
	}
	my_pixel_put(x, y, &fractal->img, ELECTRIC_BLUE);
}

/*
*	Actual sheet
*/

void	fractal_render(t_fractal *fractal)
{
	int x;
	int y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (x < WIDTH)
		{
			handle_pixel(x, y, fractal);
		}
	}
	mlx_put_image_to_window(fractal->mlx_connection,
							fractal->mlx_window,
							fractal->img.imgPtr,
							0, 0);
}

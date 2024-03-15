#incldue "fractol.h"


//Put pixel in my image buffer
static void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int offset;

	ofsett
}

void	handle_pixel()
{
	t_complex	z;
	t_fractal	c;
	int			i;
	int			color;

	i = 0;
	z.x = 0.0;
	z.y = 0.0;

	c.x = map(x, -2, 2, WIDTH);
	c.y = map(y, 2, -2, HEIGHT);

	while (i < fractol->interations_definition)
	{
		z = sum_complex(square_complex(z), c); 
		if ((z.x * z.x) + (z.y * z.y) > fractal->escape_value)
		{
			color = map(i, BLACK, WHITE, 0, fractal->interations_definition);
			my_pixel_put(); //TODO
			return ;
		}
	}  
}

 


/*
*	Actual sheet
*/

void	fract_render(t_fractal *fractal)
{
	int x;
	int y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (x < WIDTH)
		{
			handle_pixel(x, , fractal);
		}
	}
	 
}

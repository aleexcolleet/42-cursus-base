#incldue "fractol.h"

void	handle_pixel()
{
	t_complex	z;
	t_fractal	c;

	z.x = 0.0;
	z.y = 0.0;

	c.x = map(x, -2, 2, WIDTH);
	c.y = map(y, 2, -2, HEIGHT);

	while ()
	{
		z = sum_complex(square_complex(z), c); 
		if ()
		{
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

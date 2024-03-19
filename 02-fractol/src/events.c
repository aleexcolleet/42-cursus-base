#include "fractol.h"


//--When "esc" por "x" in the window--//
int	close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connection,
					fractal->img.imgPtr);
	mlx_destroy_window(fractal->mlx_connection,
					fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_connection);
	free(fractal->mlx_connection);
	exit(EXIT_SUCCESS);
}

//Keypress prototype
//
int	key_handles(int keysym, t_fractal *fractal)
{
	if (keysym == K_ESC)
		close_handler(fractal); //TODOOOO
	else if (keysym == K_LEFT)
		fractal->shift_x += (0.5 * fractal->zoom);
	else if (keysym == K_RIGHT)
		fractal->shift_x -= (0.5 * fractal->zoom);
	else if (keysym == K_UP)
		fractal->shift_y -= (0.5 * fractal->zoom);
	else if (keysym == K_DOWN)
		fractal->shift_y += (0.5 * fractal->zoom);
	else if (keysym == K_NUM_PLUS)
		fractal->iterations_definition += 10;
	else if (keysym == K_NUM_MINUS)
		fractal->iterations_definition -= 10;
	fractal_render(fractal);
	return (0);
}




//TODOOOO
/*
int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	if (button == Button5)
	{
		fractal->zoom *= 0.95;
	}
	else if (button == Button4)
	{
		fractal->zoom *= 1.05;
	}
	fractal_render(fractal);
	return (0);
}*/

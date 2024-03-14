#include "fractol.h"

//problems with malloc
static void	malloc_error(void)
{
	perror("There's a problem with malloc");
	exit(EXIT_FAILURE); 
}





/* Init
*	mlx
*	listening events and hooks data
*/

void	fractal_init(t_fractal *fractal)
{
	fractal->mlx_connection = mlx_init();
	if (NULL == fractal->mlx_connection)
		malloc_error();
	fractal->mlx_window = mlx_new_window(fractal->mlx_connection,
			WIDTH, HEIGHT, fractal->name);
	if (NULL == fractal->mlx_window)
	{
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		malloc_error();
	}
	fractal->img.imgPtr = mlx_new_image(fractal->mlx_connection, WIDTH, HEIGHT);
	if (NULL == fractal->img.imgPtr)
	{
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		malloc_error();
	}
	fractal->img.pixPtr = mlx_get_data_addr(fractal->img.imgPtr,
										 &fractal->img.bpp,
										 &fractal->img.lineLen,
										&fractal->img.endian);
	//events_init(fractal);
	//data_init(fractal); zoom, ...

}

#include "fractol.h"

t_data	init_structure(void)
{
	t_data	f;

	f.mlx_connexion = NULL;
	f.win_connexion = NULL;
	f.min_r = 0;
	f.max_r = 0;
	f.min_i = 0;
	f.max_i = 0;
	f.count = 0;
	f.color_shift = 1;
	f.resolution_shift = 0;
	f.set = 0;
	f.center_i = 0;
	f.center_r = 0;
	f.julia_shift_x = 0;
	f.julia_shift_y = 0;
	f.args = NULL;
	f.img_data = x_calloc(sizeof(t_img));
	f.color = x_calloc(sizeof(t_color));
	return (f);
}

//Initialize MLX interfaces: connection, window and image
//
//mlx_get_data_addr -----> fills in with relative to bits per pixel
//size_len and endian ---> respective provided addreses
//bits_per_pixel(how many bites per pixel color)
//size_line -------------> number of bytes to store one line of the image
//
//
//Needed to move from line to line
//mlx_get_data_addr returs a * (beggining of image in  memory). From here,
//bits_per_pixel represent the color of first pixel, in the first line.
//Second group represents the second pixel of the first line, and so on.
//Add sise_len to the adress to get the begining of the second line. 
//can reach any pixel of the image that way

void	mlx_setup(t_data *fractol)
{
	fractol->mlx_connexion = mlx_init();
	if (!fractol->mlx_connexion)
	{
		perror("Initialize error\n");
		clean_exit(fractol);
		return ;
	}
	win_gen(fractol);

	fractol->img_data->imgPtr = mlx_new_image(fractol->mlx_connexion, WIDTH, HEIGHT);
	if (!fractol->img_data->imgPtr)
	{
		clean_exit(fractol);
		ft_printf("MLX image error being created\n");
		return ;
	}
	fractol->img_data->pixPtr = mlx_get_data_addr(fractol->img_data->imgPtr,
												&fractol->img_data->bpp, \
												&fractol->img_data->lineLen,
												&fractol->img_data->endian);
	return ;
}

//Cerates mlx window and names it(fractol name)

void	win_gen(t_data *fractol)
{
	if (fractol->set == MANDELBROT)
	{
		fractol->win_connexion = mlx_new_window(fractol->mlx_connexion, WIDTH, HEIGHT, "MANDELBROT SET");
		if (!fractol->win_connexion)
		{
			clean_exit(fractol);
			ft_printf("MLX window error being created\n");
			exit(-1);
		}
	}
	else if (fractol->set == JULIA)
	{
		fractol->win_connexion = mlx_new_window(fractol->mlx_connexion, WIDTH, HEIGHT, "JULIA SET");
		if (!fractol->win_connexion)
		{
			clean_exit(fractol);
			ft_printf("MLX window error being created\n");
			exit(-1);
		}
	}
	return ;
}

void	commands_list(t_data *fractal)
{
	ft_printf("\n\n---------------------------------------------------------------------\n\n");
	ft_printf("\033[1;36m");
	ft_printf("_____________________  ________  ______________   _________________\n");
	ft_printf("__  ____/_  __ \\__   |/  /__   |/  /__    |__  | / /__  __ \\_  ___/\n");
	ft_printf("_  /    _  / / /_  /|_/ /__  /|_/ /__  /| |_   |/ /__  / / /____ \\ \n");
	ft_printf("/ /___  / /_/ /_  /  / / _  /  / / _  ___ |  /|  / _  /_/ /____/ / \n");
	ft_printf("\\____/  \\____/ /_/  /_/  /_/  /_/  /_/  |_/_/ |_/  /_____/ /____/  \n");
	ft_printf("\033[0m");
	ft_printf("\n\nW  A  S  D -------> move across screen\n");
	ft_printf("Mouse Wheel ----------> Zoom in <--> zoom out\n");
	ft_printf("ESC ------------------> quits program\n");
	ft_printf("Left Shift -----------> colors shift\n");
	ft_printf("Left Alt -------------> cycle throught resolutions(iterations++)\n");
	ft_printf("Welcome to the trip!");
	ft_printf("\n\n --------------------------------------------------------------------\n\n");

	if (fractal->set == JULIA)
		ft_printf("\nFor Julia sets right click to the current mouse");
	return ;
}

//here I'm just setting the max and min values for the complex plane
//to kinda translate the complex to imaginary values.
//Arbitrary values that works best and the function is to just range the window.
void	set_min_max(t_data *fractol)
{
	fractol->min_r = -2;
	fractol->max_r = fractol->min_r * -1 * WIDTH / HEIGHT;
	fractol->min_i = -2;
	fractol->max_i = fractol->min_i * -1 * WIDTH / HEIGHT;
	return ;
}

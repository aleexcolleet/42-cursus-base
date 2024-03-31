# include "fractol.h"

void	clean_exit(int exit_code, t_data *f)
{
	if (!f)
		exit(exit_code);
	if (f->palette)
		free(f->palette);
	if (f->img)
		mlx_destroy_image(f->mlx_con, f->img);
	if (f->win_con && f->mlx_con)
		mlx_destroy_window(f->mlx_con, f->win_con);
	if (f->mlx_con)
	{
		mlx_loop_end(f->mlx_con);
		mlx_destroy_display(f->mlx_con);
		free(f->mlx_con);
	}
	ft_printf("\nUntil the next pshycodelic trip!\n");
	exit(exit_code);
}

void	commands_list(t_data *fractal)
{
	ft_printf("\n\n--------------------------------------\n\n");
	ft_printf("\033[1;36m");
	ft_printf("_____________________  ________");
	ft_printf("______________   _________________\n");
	ft_printf("__  ____/_  __ \\__   |/  /__  ");
	ft_printf(")|/  /__    |__  | / /__  __ \\_  ___/\n");
	ft_printf("_  /    _  / / /_  /|_/ /__  /|");
	ft_printf("_/ /__  /| |_   |/ /__  / / /____ \\ \n");
	ft_printf("/ /___  / /_/ /_  /  / / _  /  ");
	ft_printf("/ / _  ___ |  /|  / _  /_/ /____/ / \n");
	ft_printf("\\____/  \\____/ /_/  /_/  /_/ ");
	ft_printf("/_/  /_/  |_/_/ |_/  /_____/ /____/  \n");
	ft_printf("\033[0m");
	ft_printf("\n\nARROWS -----------> move across screen\n");
	ft_printf("Mouse Wheel ----------> Zoom in <--> zoom out\n");
	ft_printf("ESC ------------------> quits program\n");
	ft_printf("A -----------> colors shift\n");
	ft_printf("D -----------> resolutions(iterations++)\n");
	ft_printf("Welcome to the trip!");
	ft_printf("\n\n--------------------------------------\n\n");
	if (fractal->set == JULIA)
		ft_printf("\nFor Julia sets, right click for diff params\n");
	return ;
}

void	help_msg(t_data *f)
{
	(void )f;
	ft_printf("\n+===============  Available Fractals  ===============+\n");
	ft_printf("\tMANDELBROT\t\tJULIA\n");
	ft_printf("Usage for MANDELBROT --> ./fractol Mandelbrot\n");
	ft_printf("Usage for JULIA -------> ./fractol Julia <param1> <param2>\n");
	ft_printf("Initial values must be betwen -2.0 and 2.0\n");
	ft_printf("+======================================================+\n");

}
int	end_fractol(t_data *f)
{
	clean_exit(0, f);
	return (0);
}

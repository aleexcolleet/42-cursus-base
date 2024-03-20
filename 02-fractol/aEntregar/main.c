# include "fractol.h"

int	main(int as, char **av)
{
	t_data fractol;

	if (2 == as && (!ft_strncmp(av[1], "mandelbrot ,10"))
		|| 4 == as && (!ft_strncmp(av[1], "julia", 5)))
	{
		fractol.name - av[1];
		fractol = init_structure();
		set_min_max(&f);
		f.args = av;
		check_which_fractal(&f, av[1]);
		mlx_setup(&f);
		command_list(&fractol);
		mlx_loop_hook(fractol.mlx, &generate_fractal, &fractol);
	}
	else
	{
		putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	return (0);
}

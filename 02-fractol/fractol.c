#include "fractol.h"

int	main(int as, char **av)
{
	t_data	fractol;

	if ((2 == as && (!ft_strncmp(av[1], "mandelbrot", 10)))
		|| (4 == as && (!ft_strncmp(av[1], "julia", 5))))
	{
		fractol = init_structure();
		set_min_max(&fractol);
		fractol.args = av;
		check_which_fractal(&fractol, av[1]);
		mlx_setup(&fractol);
		commands_list(&fractol);
		mlx_loop_hook(fractol.mlx_con, &generate_fractal, &fractol);
		mlx_loop(fractol.mlx_con);
	}
	else
	{
		ft_printf(ERROR_MESSAGE);
		exit(EXIT_FAILURE);
	}
	return (0);
}

//el problema es seguramente como llamo a addr i img. Tipo que los debo mezclar
//

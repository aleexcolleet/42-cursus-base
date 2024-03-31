# include "fractol.h"

static int	type_cmp(char *av, char *str)
{
	int	i;

	i = 0;
	while (av[i])
	{
		av[i] = ft_tolower(av[i]);
		i++;
	}
	if (!ft_strcmp(av, str))
		return (1);
	return (0);
}

static void	get_set(t_data *f, char **av)
{

	if (type_cmp(av[1], "mandelbrot"))
		f->set = MANDELBROT;
	else if (type_cmp(av[1], "julia"))
		f->set = JULIA;
	else
		help_msg(f);
}

static void	gen_julia_st_va(t_data *f, int ac, char **av)
{
	if (f->set != JULIA || ac == 2)
	{
		f->kr = -0.766667;
		f->ki = -0.090000;
		return ;
	}
	if (ac == 3)
		help_msg(f);
	if (!ft_strchr(av[2], '.'))
		help_msg(f);
	if (!ft_strchr(av[3], '.'))
		help_msg(f);
	f->kr = ft_atof(av[2]);
	f->ki = ft_atof(av[3]);
	if (f->kr > 2.0 || f->kr <= -2.0)
		help_msg(f);
	if (f->ki >= 2.0 || f->ki <= -2.0)
		help_msg(f);
}

static void	handle_args(t_data *f, int ac, char **av)
{
	get_set(f, av);
	gen_julia_st_va(f, ac, av);
	get_color(f, ac);
}

int	main(int as, char **av)
{
	t_data	fractol;

	if ((2 == as && (!ft_strcmp(av[1], "mandelbrot")))
		|| (4 == as && (!ft_strcmp(av[1], "julia"))))
	{
		fractol = init_structure();
		handle_args(&fractol, as, av);
		mlx_setup(&fractol);
		render(&fractol);
		commands_list(&fractol);
		mlx_hook(fractol.win_con, EVENT_CLOSE_BTN, 0, end_fractol, &fractol);
		mlx_key_hook(fractol.win_con, handle_keys, &fractol);
		mlx_mouse_hook(fractol.win_con, mouse_event, &fractol);
		mlx_loop(fractol.mlx_con);
	}
	else //falta numeros fuera del rango (2.0, -2.0)
	{
		help_msg(&fractol);
		exit(EXIT_FAILURE);
	}
	return (0);
}

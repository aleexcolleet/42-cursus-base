#include "fractol.h"

//simply checks the posible options for each set
static int	type_cmp(char *av, char *str, char c, char n)
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
	else if (av[1] == '\0' && (av[0] == c || av[0] == n))
		return (1);
	return (0);
}

//realizes the actual set wanted(1, 2, 3)
static void	get_set(t_data *f, char **av)
{
	if (type_cmp(av[1], "mandelbrot", 'm', '1'))
		f->set = MANDELBROT;
	else if (type_cmp(av[1], "julia", 'j', '2'))
		f->set = JULIA;
	else if (type_cmp(av[1], "burning ship", 'b', '3'))
		f->set = BURNING_SHIP;
	else
		help_msg(f);
}

//Checks for staring values. If not sets default ones
//If values are not valid. Returns error message
static void	get_julia_starting_values(t_data *f, int ac, char **av)
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
	if (f->kr > 2.0 || f->kr < -2.0)
		help_msg(f);
	if (f->ki >= 2.0 || f->ki <= -2.0)
		help_msg(f);
}

//Takes julia params and colors if wanted
static void	handle_args(t_data *f, int ac, char **av)
{
	get_set(f, av);
	if (f->set != JULIA && ac > 3)
		help_msg(f);
	else if (f->set == JULIA && ac > 5)
		help_msg(f);
	get_julia_starting_values(f, ac, av);
	get_color(f, ac, av);
}
//Initializes fractol data structure, prints program controls,
//opens new window and registers hooks to react to key presses.
//Loops infinetely until esc is pressed
//

int	main(int ac, char **av)
{
	t_data	f;

	if (ac < 2)
	{
		ft_printf("Error: Missing Params\n");
		print_fractal_options();
		return (2);
	}
	init_structure(&f);
	handle_args(&f, ac, av);
	init(&f);
	render(&f);
	commands_list();
	mlx_hook(f.win, ON_EVENT_CLOSE_BUTTON, 0, end_fractol, &f);
	mlx_key_hook(f.win, key_event, &f);
	mlx_mouse_hook(f.win, mouse_event, &f);
	mlx_loop(f.mlx);
	return (0);
}

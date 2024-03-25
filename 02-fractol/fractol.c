/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollet- <acollet-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:42:04 by acollet-          #+#    #+#             */
/*   Updated: 2024/01/12 15:36:26 by acollet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		write(1, "usage: ./fractol <name>\n", 24);
		write(1, "mandelbrot or julia < param 1> < param 2>\n", 42);
		exit(EXIT_FAILURE);
	}
	return (0);
}

//el problema es seguramente como llamo a addr i img. Tipo que los debo mezclar
//

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

	if ((2 == as && (!ft_strcmp(av[1], "mandelbrot")))
		|| (4 == as && (!ft_strcmp(av[1], "julia"))))
	{
		fractol = init_structure();
		set_min_max(&fractol);
		check_which_fractal(&fractol, av[1]);
		mlx_setup(&fractol);
		commands_list(&fractol);
		if (fractol.set == JULIA)
		{
			julia_shift((double)ft_atoi(av[2]),
				(double)ft_atoi(av[3]), &fractol);
		}
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

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

//every possible event within my sets

//this one handles mouse inputs
//scroll up = 4 // scroll down = 5
//left click = 1 // right click = 2

//void x and y so that if it's  not used it doesn't creat alerts

int	handle_mouse(int mousecode, int x, int y, t_data *fractol)
{
	(void)x;
	(void)y;
	if (mousecode == 4)
		mouse_zoom(fractol, 0.9, x, y);
	if (mousecode == 5)
		mouse_zoom(fractol, 1.1, x, y);
	if (mousecode == 2 && fractol->set == JULIA)
		julia_shift(x, y, fractol);
	return (0);
}

int	handle_keys(int keycode, t_data *fractol)
{
	if (keycode == ESC)
		clean_exit(fractol);
	if (keycode == A)
		shift_color(fractol);
	if (keycode == UP_ARROW)
		move(fractol, 'U');
	if (keycode == DOWN_ARROW)
		move(fractol, 'D');
	if (keycode == LEFT_ARROW)
		move(fractol, 'L');
	if (keycode == RIGHT_ARROW)
		move(fractol, 'R');
	if (keycode == D)
	{
		fractol->resolution_shift += 50;
		if (fractol->resolution_shift > 200)
			fractol->resolution_shift = 0;
		ft_printf("Max iterations %d\n",
			(fractol->resolution_shift + MAX_ITERATION));
	}
	return (0);
}

void	handle_events(t_data *fractol)
{
	mlx_hook(fractol->win_con, ON_MOUSE_DW, 0, handle_mouse, fractol);
	mlx_key_hook(fractol->win_con, handle_keys, fractol);
	mlx_hook(fractol->win_con, ON_DESTROY, 0, (void *)clean_exit, fractol);
	return ;
}

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

//increments the value of color_shifts
//loops back if max is reached
//

void	shift_color(t_data *fractol)
{
	fractol->color_shift += 1;
	if (fractol->color_shift > 5)
		fractol->color_shift = 1;
	return ;
}

//change values of rgb arbritary to get new combinations.
void	apply_shift(t_data *f)
{
	if (f->color_shift == 1)
	{
		f->color->r += 150;
		f->color->b += 10;
	}
	else if (f->color_shift == 2)
	{
		f->color->r += 70;
		f->color->b += 70;
	}
	else if (f->color_shift == 3)
		f->color->g += 75;
	else if (f->color_shift == 4)
		f->color->b += 140;
	else
	{
		f->color->b = 75;
		f->color->g += 75;
	}
	return ;
}

//get colors works the next way :)
//
//Line proggression is sequencial. From red(0) to violet(1275).
//
//POSIT		  COLOR     RGB 
//------      ------    ------
//position 0 = red = (255, 0, 0);
//position 255 = yellow = (255, 255, 0);
//position 510 = green = (0, 255, 0);
//
//This is useful to find where in the spectrum "color value" lies
//and return the int related.
//
int	get_red(int color_value)
{
	if (color_value >= 0 && color_value <= 255)
		return (255);
	else if (color_value > 255 && color_value <= 510)
		return (255 - (color_value - 255));
	else if (color_value > 510 && color_value <= 1020)
		return (0);
	else if (color_value > 1020 && color_value <= 1275)
		return (color_value - 1020);
	else
		return (255);
}

int	get_green(int color_value)
{
	if (color_value >= 0 && color_value <= 255)
		return (color_value);
	else if (color_value > 255 && color_value <= 765)
		return (255);
	else if (color_value > 765 && color_value <= 1020)
		return (255 - (color_value - 765));
	else if (color_value > 1020 && color_value <= 1275)
		return (0);
	else
		return (255);
}

int	get_blue(int color_value)
{
	if (color_value >= 0 && color_value <= 510)
		return (0);
	if (color_value > 510 && color_value <= 765)
		return (color_value - 510);
	else
		return (255);
}

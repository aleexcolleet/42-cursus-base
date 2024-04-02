# include "fractol.h"

/*	Extension of the color_shift function. Changes the color pattern.
*	The fractal can then be rendered again with different color
*	effects.
*/
static void	color_shift_striped(t_data *f)
{
	if (f->color_pattern == 2)
		set_color_zebra(f, f->color);
	else if (f->color_pattern == 3)
		set_color_triad(f, f->color);
	else 
		set_color_tetra(f, f->color);
}

/*
* 	Reinitializes the MLX image and changes the color pattern.
*	The fractal can then be rendered again with different color
*	effects.
*/

void	color_shift(t_data *f)
{
	int	alt_color;

	f->color_pattern = (f->color_pattern + 1) % 9;
	reinit_img(f);
	if (f->color == 0x000000)
		alt_color = 0x333333;
	else
		alt_color = f->color;
	if (f->color_pattern == 0)
		set_color_mono(f, alt_color);
	else if (f->color_pattern == 1)
		set_color_multiple(f, (int [4]){0x000000, alt_color,
			get_percent_color(f->color, 50), 0xFFFFFF}, 4);
	else
		color_shift_striped(f);
}

void	get_color(t_data *f, int ac)
{
	if (ac == 2 ||  (f->set == JULIA && ac == 4))
		f->color = 0x9966FF;
}

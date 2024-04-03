# include "fractol.h"

//skips '+' and 0x or 0X
static int	skip_space_sign_0x(char *color)
{
	int	i;

	i = 0;
	while (ft_isspace(color[i]))
		i++;
	if (color[i] == '+')
		i++;
	if (color[i] == '0' && (color[i + 1]
			&& (color[i + 1] == 'x' || color[i] == 'X')))
		i = i + 2;
	return (i);
}

//converts hexadecimal color into a valid integer.
static int	ft_atox_color(t_data *f, char *color)
{
	int	i;
	int	x;
	int	n;

	n = 0;
	i = 0;
	i = skip_space_sign_0x(color);
	x = 0;
	while (color[i] && ft_ishexdigit(color[i]))
	{
		if (ft_isdigit(color[i]))
			n = (n * 16) + (color[i] - '0');
		else
			n = (n * 16) + (ft_toupper(color[i]) - 'A' + 10);
		i++;
		x++;
	}
	if (x == 6 && !color[i])
		return (n);
	else
		help_msg(f);
	return (-1);
}

//gets the color provided. If not, default one
void	get_color(t_data *f, int ac, char **av)
{
	if (f->set == JULIA && ac == 5)
		f->color = ft_atox_color(f, av[4]);
	else if (f->set != JULIA && ac == 3)
		f->color = ft_atox_color(f, av[2]);
	if (ac == 2 || (f->set == JULIA && ac == 4))
		f->color = 0x9966FF;
}

//Reinitializes the color pattern
//So that when render acts again, the colors
//are different;
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
		color_shift_stripped(f);
}

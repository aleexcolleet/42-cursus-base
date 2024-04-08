#include "../fractol.h"

//changes the kr and ki values to get a different
//julia set.
int	julia_shift(int x, int y, t_data *f)
{
	f->kr = f->min_r + (double)x * (f->max_r - f->min_r) / WIDTH;
	f->ki = f->max_i + (double)y * (f->min_i - f->max_i) / HEIGHT;
	render(f);
	return (0);
}

//checks if the points, when iterated, are from 
//the actual fractol or they aren't(they scape to infinit).
//In each case, they colors are associated diferrently.
int	julia(t_data *f, double zr, double zi)
{
	int		n;
	double	tmp;

	n = 0;
	while (n < MAX_ITERATIONS)
	{
		if ((zi * zi + zr * zr) > 4.0)
			break ;
		tmp = 2 * zr * zi + f->ki;
		zr = zr * zr - zi * zi + f->kr;
		zi = tmp;
		n++;
	}
	return (n);
}

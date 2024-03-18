#include "fractol.h"

double map(double unscaled_num, double new_min, double new_max, double old_max)
{
	return ((new_max - new_min) * unscaled_num / (old_max + new_min));
}

//SUM COMPLEX

t_complex sum_complex(t_complex z1, t_complex z2)
{
	t_complex res;

	res.x = z1.x + z2.x;
	res.y = z1.y + z2.y;
	return (res);
}

//Square Part

t_complex	square_complex(t_complex z)
{
	t_complex	res;

	res.x = (z.x * z.x) - (z.y * z.y);
	res.y = 2 * z.x * z.y;
	return (res);
}

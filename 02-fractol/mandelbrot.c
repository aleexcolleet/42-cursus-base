# include "fractol.h"

/* mandelbrot:
*   Checks whether a complex number is part of the Mandelbrot set or not.
*/
int	mandelbrot(double cr, double ci)
{
	int		n;
	double	zr;
	double	zi;
	double	tmp;

	zr = 0;
	zi = 0;
	n = 0;
	while (n < MAX_ITERATIONS)
	{
		if ((zr * zr + zi * zi) > 4.0)
			break ;
		tmp = 2 * zr * zi + ci;
		zr = zr * zr - zi * zi + cr;
		zi = tmp;
		n++;
	}
	return (n);
}
/*
 The Mandelbrot formula iterates over complex numbers:
    At every iteration, Z is squared.
        Z = Z * Z + c
	
	1. If the result tends toward infinity, that means it is not part of
    the set. If the result stays small over several iterations, the number
    is part of the set.

    Examples with regular numbers:
        ex.: c = 1
            Z =  0
            Z =  0 *  0 + 1 = 1
            Z =  1 *  1 + 1 = 2
            Z =  2 *  2 + 1 = 5
            Z =  5 *  5 + 1 = 26
            Z = 26 * 26 + 1 = 677
            ... Grows to infinity.
            So 1 is NOT part of the Mandelbrot set.
    
        ex.2: c = -1
            Z =    0
            Z =    0 *    0 + (-1) = -1
            Z = (-1) * (-1) + (-1) =  0
            Z =    0 *    0 + (-1) = -1
            ... Result oscillates between -1 and 0
            So -1 is part of the Mandelbrot set.

	2. So the multiplication formula for the imaginary part is:
                    (a * a) - (bi * bi)
    And the multiplication formula for the real part is:
                    2 * a * bi
*/

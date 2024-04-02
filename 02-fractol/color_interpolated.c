# include "fractol.h"


//this function separates the red, green and blue components of both colors.
//Then calculates the interpolated value for each color component with the formula
//the combines them in one integer.
//
/* interpolate: calculates unknown colors betwen known colors
*	Interpolates between two hex colors. Each color channel must be
*	calculated separately according to the formula:
*		(endValue - startValue) * stepNumber / lastStepNumber + startValue
*	The fractional component (stepNumber / lastStepNumber) must be provided
*	as fraction parameter of this function.
*	Note: rgb[3] : [0] = red, [1] = green, [2] = blue
*/
static int	interpolate(int startcolor, int endcolor, double fraction)
{
	int	start_rgb[3];
	int	end_rgb[3];

	start_rgb[0] = ((startcolor >> 16) & 0xFF);
	start_rgb[1] = ((startcolor >> 8) & 0xFF);
	start_rgb[2] = ((startcolor >> 0) & 0xFF);
	end_rgb[0] = ((endcolor >> 16) & 0xFF);
	end_rgb[1] = ((endcolor >> 8) & 0xFF);
	end_rgb[2] = ((endcolor >> 0) & 0xFF);
	start_rgb[0] = (end_rgb[0] - start_rgb[0]) * fraction + start_rgb[0];
	start_rgb[1] = (end_rgb[1] - start_rgb[1]) * fraction + start_rgb[1];
	start_rgb[2] = (end_rgb[2] - start_rgb[2]) * fraction + start_rgb[2];
	return (0xFF << 24 | start_rgb[0] << 16 | start_rgb[1] << 8 | start_rgb[2]);
}

//initializes color to black and color2 to the provided color.
//basically this fills the palet with monocromatic colors
void	set_color_mono(t_data *f, int color)
{
	int		i;
	int		j;
	double	fraction;
	int		color1;
	int		color2;

	color1 = 0x000000;
	color2 = color;
	i = 0;
	while (i < MAX_ITERATIONS)
	{
		j = 0;
		while (j < MAX_ITERATIONS / 2)
		{
			fraction = (double)j / (MAX_ITERATIONS / 2);
			f->palette[i + j] = interpolate(color1, color2, fraction);
			j++;
		}
		color1 = color2;
		color2 = 0xFFFFFF;
		i += j;
	}
	f->palette[MAX_ITERATIONS -1] = 0;
}

/* set_color_multiple:
*	Sets a multicolor color scheme. Colors range from the
*	first color provided in the array to the last. The colors are
*	interpolated for a smooth transition between each. 
*/

void	set_color_multiple(t_data *f, int colors[4], int n)
{
	int		i;
	int		j;
	int		x;
	double	fraction;

	i = 0;
	x = 0;
	while (i < MAX_ITERATIONS)
	{
		j = 0;
		while ((i + j) < MAX_ITERATIONS && j < (MAX_ITERATIONS / (n - 1)))
		{
			fraction = (double)j / (MAX_ITERATIONS / (n - 1));
			f->palette[i + j] = interpolate(colors[x], colors[x + 1], fraction);
			j++;
		}
		x++;
		i += j;
	}
	f->palette[MAX_ITERATIONS - 1] = 0;
}

# include "fractol.h"

//Zoom by adding the complex number edge values a zoom
//multiplier.
//Calculate differently the center_i and center_x
//because of negative values supression
//0.5 for '+'
//2.0 for '-'
static void	zoom(t_data *f, double zoom)
{
	double	center_i;
	double	center_x;

	center_r = f->min_r - f->max_r;
	center_i = f->max_i - f->min_i;
	f->max_r = f->max_r + (center_r - zoom * center_r) / 2;
	f->min_r = f->max_r + zoom * center_r;
	f->min_i = f->min_i + (center_i - zoom * center_i) / 2;
	f->max_i = f->min_i + zoom * center_i;
}

//moves the view of the fractal by displacing
//the complex number edge a certain distance in a x
//direction.
static void	move(t_data *f, double distance, char direction)
{
	double center_r;
	double center_i;

	center_r = f->max_r - f->min_r;
	center_i = f->max_i - f->min_i;
	if (direction == 'R')
	{
		f->min_r += distance * center_r;
		f->max_r += distance * center_r;
	}
	else if (direction == 'L')
	{
		f->min_r -= distance * center_r;
		f->max_r -= distance * center_r;
	}
	else if (direction == 'U')
	{
		f->min_i += distance * center_i;
		f->max_i += distance * center_i;
	}
	else if (direction == 'D')
	{
		f->min_i -= distance * center_i;
		f->max_i -= distance * center_i;
	}
}

//this will be automatically called when a 
//key is pressed. If a valid event is detected,
//settings are adjusted and the fractal is
//rendered again
int	key_event(int keycode, t_data *mlx)
{
	if (keycode == KEY_ESC)
	{
		end_fractol(mlx);
		return (0);
	}
	else if (keycode == KEY_PLUS)
		zoom(mlx, 0.5);
	else if (keycode == KEY_MINUS)
		zoom(mlx, 2);
	else if (keycode == ARROW_UP || ON_KEY_W)
		move(mlx, 0.2, 'U');
	else if (keycode == ARROW_DOWN || ON_KEY_S)
		move(mlx, 0.2, 'D');
	else if (keycode == ARROW_LEFT || ON_KEY_A)
		move(mlx, 0.2, 'L');
	else if (keycode == ARROW_RIGHT || ON_KEY_D)
		move(mlx, 0.2, 'R');
	else if (keycode == ON_SPACE)
		color_shift(mlx);
	else if (!key_event_extended(keycode, mlx))
		return (1);
	else
		return (1);
	render(mlx);
	return (0);

}

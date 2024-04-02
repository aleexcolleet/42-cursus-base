# include "fractol.h"

static void	zoom(t_data *f, double zoom)
{
	double	center_r;
	double	center_i;

	center_r = f->min_r - f->max_r;
	center_i = f->max_i - f->min_i;
	f->max_r = f->max_r + (center_r - zoom * center_r) / 2;
	f->min_r = f->max_r + zoom * center_r;
	f->min_i = f->min_i + (center_i - zoom * center_i) / 2;
	f->max_i = f->min_i + zoom * center_i;
}

static void	move(t_data *f, double distance, char direction)
{
	double	center_r;
	double	center_i;

	center_r = f->max_r - f->min_r;
	center_i = f->max_i - f->min_i;
	if (direction == 'R')
	{
		f->min_r += center_r * distance;
		f->max_r += center_r * distance;
	}
	else if (direction == 'L')
	{
		f->min_r -= center_r * distance;
		f->max_r -= center_r * distance;
	}
	else if (direction == 'D')
	{
		f->min_i -= center_i * distance;
		f->max_i -= center_i * distance;
	}
	else if (direction == 'U')
	{
		f->min_i += center_i * distance;
		f->max_i += center_i * distance;
	}
}

int	handle_keys(int keycode, t_data *fractol)
{
	if (keycode == ESC)
	{
		end_fractol(fractol);
		return (0);
	}
	else if (keycode == A)
		zoom(fractol, 0.5);
	else if (keycode == D)
		zoom(fractol, 2);
	else if (keycode == UP_ARROW)
		move(fractol, 0.2, 'U');
	else if (keycode == DOWN_ARROW)
		move(fractol, 0.2, 'D');
	else if (keycode == LEFT_ARROW)
		move(fractol, 0.2, 'L');
	else if (keycode == RIGHT_ARROW)
		move(fractol, 0.2, 'R');
	else if (keycode == W)
		color_shift(fractol);
	else
		return (1);
	render(fractol);
	return (0);
}

int	mouse_event(int keycode, int x, int y, t_data *mlx)
{
	if (keycode == MOUSE_WHEEL_UP)
	{
		zoom(mlx, 0.5);
		x -= WIDTH / 2;
		y -= HEIGHT / 2;
		if (x < 0)
			move(mlx, (double)x * -1 / WIDTH, 'L');
		else if (x > 0)
			move(mlx, (double)x / WIDTH, 'R');
		if (y < 0)
			move(mlx, (double)y * -1 / HEIGHT, 'U');
		else if (y > 0)
			move (mlx, (double)y / HEIGHT, 'D');
	}
	else if (keycode == MOUSE_WHEEL_DOWN)
		zoom(mlx, 2);
	else if (keycode == MOUSE_BTN)
	{
		if (mlx->set == JULIA)
			julia_shift(x, y, mlx);
	}
	else
		return (0);
	render(mlx);
	return (0);
}


/* Cuidado porque creo que falta la parte de
 * la resolucion
 
	
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
}*/

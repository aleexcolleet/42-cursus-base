#include "fractol.h"

void	clean_exit(t_data *fractol)
{
	if (fractol->img_data->imgPtr)
	{
		mlx_destroy_image(fractol->mlx_connexion, fractol->win_connexion);
		free(fractol->img_data);
	}
	if (fractol->win_connexion)
		mlx_destroy_window(fractol->mlx_connexion, fractol->win_connexion);
	if (fractol->color)
		free(fractol->color);
	write(1, "until the next pshycodelic trip!", 32);
	exit(0);
}

//these functions alters the center based on zoom value
//right border position will be moved to a side, and let one has to
//compensate it moving to the opposite side
/*
void	mouse_zoom(t_data *f, double zoom, int x, int y)
{
	(void)x;
	(void)y;
	f->center_r = f->min_r - f->max_r;
	f->center_i = f->max_i - f->min_i;
	f->max_r = f->max_r + (f->center_r - zoom * f->center_r) / 2;
	f->min_r = f->max_r + zoom * f->center_r;
	f->max_i = f->min_i + zoom * f->center_i;
	f->min_i = f->min_i + (f->center_i - zoom * f->center_i) / 2;
}
*/
//this function uses imag adress(pixPtr) 
//finds the relative pixel to the x and y.
//
//y * lenght = actual line.
//x * bits per pixel / 8 = number of bytes. (1 pixel = 32 bytes)
//then changed the pixel to the required color
//
void	my_px_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->pixPtr + (y * img->lineLen + x * (img->bpp / 8));
	*(int *)pixel = color;
}

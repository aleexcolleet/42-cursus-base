#include "fractol.h"

void	clean_exit(t_data fractol)
{
	if (fractol->img_data->img)
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

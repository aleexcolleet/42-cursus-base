#include "fractol.h"

void	handle_events(t_data *fractol)
{
	mlx_hook(fractol->win_connexion, ON_MOUSE_DW, 0, handle_mouse, fractol);
	mlx_key_hook(fractol->win_connexion, handel_keys, fractol);
	mlx_hook(fractol->win_connexion, ON_DESTROY, 0, (void *)clean_exit, fractol);
	return ;
}

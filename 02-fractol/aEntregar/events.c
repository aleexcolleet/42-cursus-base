#include "fractol.h"

//every possible event within my sets

//this one handles mouse inputs
//scroll up = 4 // scroll down = 5
//left click = 1 // right click = 2

//void x and y so that if it's  not used it doesn't creat alerts
/*
int	handle_mouse(int mousecode, int x, int y, t_data *fractol)
{
	(void)x;
	(void)y;
	if (mousecode == 4)
		mouse_zoom(fractol, 0.9, x, y);
	if (mousecode == 5)
		mouse_zoom(fractol, 1.1, x, y);
	if (mousecode == 2 && fractol->set == JULIA)
		julia_shift(x, y, fractol);
	return (0);
}
*/

void	handle_events(t_data *fractol)
{
//	mlx_hook(fractol->win_connexion, ON_MOUSE_DW, 0, handle_mouse, fractol);
//	mlx_key_hook(fractol->win_connexion, handel_keys, fractol);
	mlx_hook(fractol->win_connexion, ON_DESTROY, 0, (void *)clean_exit, fractol);
	return ;
}

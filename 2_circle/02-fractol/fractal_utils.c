#include "fractol.h"

//frees everything if it has been initializes. Also gives
//exit code.
void	clean_exit(int exit_code, t_data *f)
{
	if (!f)
		exit(exit_code);
	if (f->palette)
		free(f->palette);
	if (f->img)
		mlx_destroy_image(f->mlx, f->img);
	if (f->win)
		mlx_destroy_window(f->mlx, f->win);
	ft_printf("\nPsychodelic trip ended. See you next time!\n\n");
	exit(exit_code);
}

//This returns an error message to the standard error.
//
int	message(char *str1, char *str2, int errnum)
{
	ft_putstr_fd("Fractol: ", 2);
	ft_putstr_fd(str1, 2);
	ft_putendl_fd(str2, 2);
	return (errnum);
}

//FUNCTION TO QUIT CORRECTLY WHEN ESC IS PRESSED
//
int	end_fractol(t_data *mlx)
{
	clean_exit(0, mlx);
	return (0);
}

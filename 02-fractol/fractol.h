#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h> //awesome for debugging(printf)
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "minilibx-mac-osx/mlx.h"

#define ERROR_MES "Please enter \n\t\"./fractol mandelbro\" or \n\t\"./fractol julia <value_1> <value_2>\""

/* using a square
 * so that math rendering 
 * part is simple
*/
#define WIDTH  800
#define HEIGHT 800

//COMPLEX VALUE 
typedef struct s_complex
{
	double x;
	double y;
  
}	t_complex;


/*
* IMAGE
* Pixels buffer
*/
typedef struct s_img
{
	void	*imgPtr;//pointer to imagef struct
	char	*pixPtr;//points to the actual pixels_ptr
	int		bpp;
	int		endian;
	int		lineLen;
}	t_img;

/*
 *	Fractal ID (STTRUCTURE)
 *	MLKS, image, hooks values
 */

typedef struct s_fractal
{
	char *name;
	//MLKS
	void	*mlxs_connection;// mlx_init
	void	*mlxs_window;// mlx_new_window
	//image
	t_img img;

	//hooks member variables //TODO
} t_fractal;


/*
 PROTOTYPES
*/


//string utils
int			ft_strncmp(char *s1, char *s2, int nbr);
void		putstr_fd(char *s, int fd);

//INIT
void		fractal_init(t_fractal *fractal);

//math part
double		map(double unscaled_num, double new_min, double new_max, double old_max);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);

#endif

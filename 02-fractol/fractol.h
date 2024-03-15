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

//COLORS
// Color Defines
#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN "\x1b[36m"
#define WHITE "\x1b[37m"
#define RESET "\x1b[0m"


//PSHYCHEDELIC COLORS
#define PSYCHEDELIC_RED "\x1b[38;2;255;0;0m"     // Vibrant RED
#define PSYCHEDELIC_GREEN "\x1b[38;2;0;255;0m"   // Electric GREEN
#define PSYCHEDELIC_BLUE "\x1b[38;2;0;0;255m"    // Intense BLUE
#define PSYCHEDELIC_YELLOW "\x1b[38;2;255;255;0m"// Bright YELLOW
#define PSYCHEDELIC_MAGENTA "\x1b[38;2;255;0;255m" // Psychedelic MAGENTA
#define PSYCHEDELIC_CYAN "\x1b[38;2;0;255;255m"  // CYAN, a staple of psychedelic art
#define PSYCHEDELIC_ORANGE "\x1b[38;2;255;165;0m" // Vivid ORANGE
#define PSYCHEDELIC_PURPLE "\x1b[38;2;128;0;128m" // Deep PURPLE
#define PSYCHEDELIC_LIME "\x1b[38;2;191;255;0m"   // LIME GREEN
#define PSYCHEDELIC_PINK "\x1b[38;2;255;105;180m" // Bright PINK




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
	double	escape_value; //hypotenous
	int	iterations_definition;
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

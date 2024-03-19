#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h> //TODO debugging
# include <stdlib.h> //malloc free
# include <unistd.h> // write
# include <math.h>

#define ERROR_MESSAGE "Please enter \n\t\"./fractol mandelbrot\" or \n\t\"./fractol julia <value_1> <value_2>\"\n"

//window settings
#define WIDTH	800
#define	HEIGHT	800

//Normal colors
#define BLACK       0x000000  // RGB(0, 0, 0)
#define WHITE       0xFFFFFF  // RGB(255, 255, 255)
#define RED         0xFF0000  // RGB(255, 0, 0)
#define GREEN       0x00FF00  // RGB(0, 255, 0)
#define BLUE        0x0000FF  // RGB(0, 0, 255)

// Psychedelic colors
#define MAGENTA_BURST   0xFF00FF  // A vibrant magenta
#define LIME_SHOCK      0xCCFF00  // A blinding lime
#define NEON_ORANGE     0xFF6600  // A blazing neon orange
#define PSYCHEDELIC_PURPLE 0x660066  // A deep purple
#define AQUA_DREAM      0x33CCCC  // A bright turquoise
#define HOT_PINK        0xFF66B2  // As the name suggests!
#define ELECTRIC_BLUE   0x0066FF  // A radiant blue
#define LAVA_RED        0xFF3300  // A bright, molten RED

//STRUCT VALUES
//
//s_complex
typedef struct	s_complex
{
	//		real
	double	x;
	//		i
	double	y;
}				t_complex;

//IMAGE

typedef struct s_img
{
	void	*imgPtr;
	char	*pixPtr;
	int		bpp;
	int		endian;
	int		lineLen;
}				t_img;

//FRACTAL

typedef struct s_fractal
{
	char	*name;
	void	*mlx_connection;
	void	*mlx_window;
	t_img	img;

	double	escape_value;
	int		iterations_definition;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
}				t_fractal;

//PROTOTYPES

//INIT 
void	data_init(t_fractal *fractal);
void	events_init(t_fractal *fractal);
void	fractal_init(t_fractal *fractal);

//math utils
double map(double unscaled_num, double new_min, double new_max, double old_max);
t_complex sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);

//Render
void	fractal_render(t_fractal *fractal);

//string utils
double	special_atoi(char *s);
int	ft_strncmp(char *s1, char *s2, int nbr);
void	putstr_fd(char *s, int fd);

//hooks events
int	close_handler(t_fractal *fractal);
int	key_handles(int keysym, t_fractal *fractal);
int	mouse_handler(int button, int x, int y, t_fractal *fractal);

#endif

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <unistd.h>

#define ERROR_MESSAGE "Please enter \n\t\"./fractol mandelbrot\" or \n\t\"./fractol julia <value_1> <value_2>\"\n"
//main DEFINES
# define MAX_ITERATION 25
# define MANDELBROT 1
# define JULIA 2
//MLBX
# include "./libft/libft.h"
# include  "./minilibx_opengl_20191021/mlx.h"

//DEFAULTS
# define WIDTH 1250
# define HEIGHT 1250

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

//EVENTS
enum {
	W = 13,
	A = 0,
	S = 1,
	D = 2,
	UP_ARROW = 126,
	DOWN_ARROW = 125,
	LEFT_ARROW = 123,
	RIGHT_ARROW = 124,
	LEFT_CTRL = 256,
	LEFT_ALT = 261,
	LEFT_SHIFT = 257,
	ESC			= 53,
	ON_DESTROY	= 17,
	ON_MOUSE_DW	= 4,
};

//STRUCTURES
//
//COLORS
typedef struct s_color
{
	int	red;
	int	green;
	int	blue;
	int	t;
}				t_color;

//COMPLEX NUMBER
typedef struct	s_complex
{
	double	x;
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

typedef struct s_data
{
	void			*mlx_connexion;
	void			*win_connexion;
	t_img			*img_data;
	t_color			*color;
	double			min_r;
	double			max_r;
	double			min_i;
	double			max_i;
	unsigned int	count;
	int				color_shift;
	int				resolution_shift;
	int				set;
	double			center_i;
	double			center_r;
	double			julia_shift_x;
	double			julia_shift_y;
	char			**args;
}	t_data;	

//PROTOTYPES
//
// INIT
void	set_min_max(t_data *fractol);
void	commands_list(t_data *fractol);
void	win_gen(t_data *fractol);
void	mlx_setup(t_data *fractol);
t_data	init_structure(void);

//COLORS
//
int	get_blue(int color_value);
int	get_green(int color_value);
int	get_red(int	color_value);
void	apply_shift(t_data *fractol);

//EVENTS
//
void	handle_events(t_data *fractol);
int	handle_mouse(int mousecode, int x, int y, t_data *fractol);

//FRACT_UTILS
//
void	my_px_put(t_img *img, int x, int y, int color);
void	mouse_zoom(t_data *f, double zoom, int x, int y);
void	clean_exit(t_data *fractol);

//MANDELBROT
//
void	generate_mandelbrot(t_data *fractol);
int	is_actually_mandel(double yf, double yi, t_data *fractol);

//RENDER
//
int	make_color(t_data *fractol);
int	create_trgb(int t, int r, int g, int b);
int	generate_fractal(t_data *fractol);
void	check_which_fractal(t_data *fractol, char *arg);

#endif

# include "fractol.h"

void	init_structure(t_data *f)
{
	f->mlx_con = NULL;
	f->win_con = NULL;
	f->img = NULL;
	f->buf = NULL;
	f->set = -1;
	f->min_r = 0;
	f->max_r = 0;
	f->min_i = 0;
	f->max_i = 0;
	f->kr = 0;
	f->ki = 0;
	f->sx = 0;
	f->rx = 0;
	f->fx = 0;
	f->palette = NULL;
	f->color_pattern = -1;
	f->color = 0;
}

//Specific ranges for sets. Julia needs a bit more space
//to the right than mandel.
void	get_complex_layout(t_data *f)
{
	if (f->set == MANDELBROT)
	{
		f->min_r = -4.0;
		f->max_r = 4.0;
		f->min_i = -4.0;
		f->max_i = f->min_i + (f->max_r - f->min_r) * HEIGHT / WIDTH;
	}
	else
	{
		f->min_r = -2.0;
		f->max_r = 2.0;
		f->min_i = -2.0;
		f->max_i = f->min_i + (f->max_r - f->min_r) * HEIGHT / WIDTH;
	}
}

//initializes the mlx image and a color palette.
static void	init_img(t_data *f)
{
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	char	*buf;

	f->palette = ft_calloc((MAX_ITERATIONS + 1), sizeof(int));
	if (!(f->palette))
		clean_exit(0, f);
	f->img = mlx_new_image(f->mlx_con, WIDTH, HEIGHT);
	if (!(f->img))
		clean_exit(0, f);
	buf = mlx_get_data_addr(f->img, &pixel_bits, &line_bytes, &endian);
	f->buf = buf;
}


void	reinit_img(t_data *f)
{
	if (f->mlx_con && f->img)
		mlx_destroy_image(f->mlx_con, f->img);
	if (f->palette)
		free(f->palette);
	if (f->buf)
		f->buf = NULL;
	init_img(f);
}

void	mlx_setup(t_data *f)
{
	f->mlx_con = mlx_init();
	if (!f->mlx_con)
	{
		perror("Initialize error\n");
		clean_exit(0, f);
		return ;
	}
	if (f->set == MANDELBROT)
	{
		f->win_con = mlx_new_window(f->mlx_con,
				WIDTH, HEIGHT, "MANDELBROT SET");
	}
	else if (f->set == JULIA)
	{
		f->win_con = mlx_new_window(f->mlx_con,
				WIDTH, HEIGHT, "JULIA SET");
	}
	if (!f->win_con)
	{
		clean_exit(0, f);
		ft_printf("MLX window error being created\n");
		exit(-1);
	}
	f->sx = 2.0;
	f->rx = 0.5;
	f->fx = 1.0;
	get_complex_layout(f);
	color_shift(f);
	return ;
}

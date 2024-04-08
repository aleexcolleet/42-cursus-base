#include "fractol.h"

//Fractal options. 
//
void	print_fractal_options(void)
{
	ft_printf("+-------------  Available Fractals  ------------+\n");
	ft_printf("\tM - Mandelbrot\n");
	ft_printf("\tJ - Julia\n");
	ft_printf("\tB - Burning Ship\n");
	ft_printf("\e[36mUsage example:\n\t./fractol <type>\n\t./fractol M\e[0m");
	ft_printf("\nFor Julia, you may specify starting values for the\n");
	ft_printf("initial fractal shape. Values must be between\n");
	ft_printf("-2.0 and 2.0 and must contain a decimal point.\n");
	ft_printf("\e[36mUsage example:\t\n");
	ft_printf("\t./fractol J\n\t./fractol J 0.285 0.01\e[0m\n");
}

void	print_color_options(void)
{
	ft_printf("\n+===============  Possible colors  ====================+\n\n");
	ft_printf("Pick a starting color in hexadecimal code.\n");
	ft_printf("\tFormatted as RRGGBB:\n");
	ft_printf("\tWhite:\tFFFFFF\t\tBlack:\t000000\n");
	ft_printf("\tRed:\tFF0000\t\tGreen:\t00FF00\n");
	ft_printf("\tBlue:\t0000FF\t\tYellow:\tFFFF00\n");
	ft_printf("\tPurple:\t9933FF\t\tOrange:\tCC6600\n");
	ft_printf("\tPink:\tFF3399\t\tTurquoise: 00FF80\t\n");
	ft_printf("\n\e[36mUsage example:\t\n");
	ft_printf("\t./fractol <type> <color>\n");
	ft_printf("\t\t./fractol M 0000FF\e[0m");
	ft_printf("\nFor Julia, you can only specify colors after ");
	ft_printf("the starting values.\n");
	ft_printf("\e[36mUsage example:\t\n");
	ft_printf("\t./fractol J 0.285 0.01 CC6600\e[0m\n\n");
}

void	commands_list(void)
{
	ft_printf("\n\n--------------------------------------\n\n");
	ft_printf("\033[1;36m");
	ft_printf("_____________________  ________");
	ft_printf("______________   _________________\n");
	ft_printf("__  ____/_  __ \\__   |/  /__  ");
	ft_printf(")|/  /__    |__  | / /__  __ \\_  ___/\n");
	ft_printf("_  /    _  / / /_  /|_/ /__  /|");
	ft_printf("_/ /__  /| |_   |/ /__  / / /____ \\ \n");
	ft_printf("/ /___  / /_/ /_  /  / / _  /  ");
	ft_printf("/ / _  ___ |  /|  / _  /_/ /____/ / \n");
	ft_printf("\\____/  \\____/ /_/  /_/  /_/ ");
	ft_printf("/_/  /_/  |_/_/ |_/  /_____/ /____/  \n");
	ft_printf("\033[0m");
	ft_printf("\n\nARROWS or WASD ---------> move across screen\n");
	ft_printf("Mouse Wheel or + - ---------> Zoom\n");
	ft_printf("ESC ------------------> quits program\n");
	ft_printf("SPACE BAR -----------> colors shift\n");
	ft_printf("Switch fractals -----> (1, 2, 3)\n");
	ft_printf("Left click or shift -----------> (J ONLY) resolution\n");
	ft_printf("Welcome to the trip!");
	ft_printf("\n\n--------------------------------------\n\n");
	return ;
}

//Prints a help message in order to explain the program
void	help_msg(t_data *f)
{
	ft_printf("\n+--------------------------------------------------+\n");
	ft_printf("		 	 FRACTOL HELP SHEET\n");
	ft_printf("+--------------------------------------------------+\n\n");
	print_fractal_options();
	print_color_options();
	clean_exit(0, f);
}

#include <stdio.h>

void	ft_prueba(void)
{
	printf("\n\n---------------------------------------------------------------------\n\n");
	printf("\033[1;36m");
	printf("_____________________  ________  ______________   _________________\n");
	printf("__  ____/_  __ \\__   |/  /__   |/  /__    |__  | / /__  __ \\_  ___/\n");
	printf("_  /    _  / / /_  /|_/ /__  /|_/ /__  /| |_   |/ /__  / / /____ \\ \n");
	printf("/ /___  / /_/ /_  /  / / _  /  / / _  ___ |  /|  / _  /_/ /____/ / \n");
	printf("\\____/  \\____/ /_/  /_/  /_/  /_/  /_/  |_/_/ |_/  /_____/ /____/  \n");
	printf("\033[0m");

	printf("\n\nW  A  S  D -------> move across screen\n");
	printf("Mouse Wheel ----------> Zoom in <--> zoom out\n");
	printf("ESC ------------------> quits program\n");
	printf("Left Shift -----------> colors shift\n");
	printf("Left Alt -------------> cycle throught resolutions(iterations++)\n");
	printf("Welcome to the trip!");
	printf("\n\n --------------------------------------------------------------------\n\n");
	return ;
}

int main(void)
{
	ft_prueba();
	return (0);
}

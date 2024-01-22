#include "ft_printf.h"

int	ft_putchar(char c, int j) //on succes write returns (-1);
{
	if (j == -1)
		return (-1);
	else if (write(1, &c, 1) == -1)
		return (-1);
	j++;
	return (j);
}

//write() = -1 si funciona

#include "/Users/aleexcolleet/Desktop/42journey/01-ft_printf/library/ft_printf.h"

int	ft_putchar(char c, int i) //on succes write returns (-1);
{
	if (i == -1)
		return (-1);
	else if (write(1, &c, 1) == -1)
		return (-1);
	i++;
	return (i);
}

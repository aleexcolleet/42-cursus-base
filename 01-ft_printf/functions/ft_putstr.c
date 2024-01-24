#include "ft_printf.h"

int	ft_putstr(const char *str, int j)
{
	if (str == NULL)
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		j += 6;
		return (j);
	}
	while (*str)
	{
		j = ft_putchar(*str, j);
		if (j == -1)
			return (-1);
		str++;
	}
	return (j);
}

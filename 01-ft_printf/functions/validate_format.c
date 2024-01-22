#include "ft_printf.h"

int	validate_format(va_list args, char const *format, int i, int j)
{
	if (format[i] == 'c')
		j = ft_putchar(va_arg(args, int), i);
	return (j);
}

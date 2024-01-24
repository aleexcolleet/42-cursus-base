#include "ft_printf.h"

int	validate_format(va_list args, char const *format, int i, int j)
{
	if (format[i] == 'c')
		j = ft_putchar(va_arg(args, int), j);
	if (format[i] == 's')
		j = ft_putstr(va_arg(args, char *), j);
	if (format[i] == 'p')
		j = print_adress(va_arg(args, void *), j);

	if (j == -1)
		return (-1); //por lo que putchar a funcionado correctamente
	return (j);

//j = -1; se ha imprimido
//j = 1; no se imprimio
}

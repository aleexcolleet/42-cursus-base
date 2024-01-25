#include "ft_printf.h"

int	ft_printf(char const *format, ...)
{
	int	i;
	int	j;
	va_list args;
	
	i = -1; //itera el argumento
	j = 0; //recibe el lenght que devuelve printf.
	va_start(args, format);
	while(format[++i])
	{
		if (format[i] == '%')
		{
			i++;
			if (ft_strchr("cspdiuxX%", format [i]))
				j = validate_format(args, format, i , j);	
		}
		else
			j = ft_putchar(format[i], j);
		if (j == -1)
			return (-1);
	}
	va_end(args);
	return (j);
}

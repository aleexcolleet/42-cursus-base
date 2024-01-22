#include "ft_printf.h"
#include "libft.h"

char *ft_putstr(const char *str, int j, int i)
{
	if (j == -1)
		return (-1);
	else if (!*str)
		write(1, "NULL", 4);
	if (write(1, str, ft_strlen(str)) == -1)
		j = -1;
	return (j);
}

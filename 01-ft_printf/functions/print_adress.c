#include "ft_printf.h"

int	print_adress(void *ptr, int j)
{
	if (ptr == NULL)
	{
		if (write(1, "0x0", 3) == -1)
			return (-1);
		j += 3;
		return (j);
	}
	//j = ft_putstr("0x", j);
	write(1, "0x", 2);
	j += 2;
	j = print_adress_hex((unsigned long long)ptr, j);
	return (j);
}
static int	print_adress_hex(unsigned long long vptr, int j)
{
	char	*hex;
	int		result[20];
	int		y;

	if (j == -1)
		return (-1);
	hex = "0123456789abcdef";
	y = 0;
	while (vptr > 0)
	{
		result[y] = hex[vptr % 16];
		vptr = vptr / 16;
		y++;
	}
	while (y >= 0)
	{
		j = ft_putchar(result[y], j);
		y--;
	}
	if (j == -1)
		return (-1);
	return(j);
}

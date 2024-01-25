#include "ft_printf.h"

int	ft_hexlen(unsigned int n)
{
	int	lenght;

	lenght = 0;
	while (n != 0)
	{
		n = n / 16;
		lenght++;
	}
	return (lenght);
}
void	ft_printhex(unsigned int n, const char format, int j)
{
	if (n >= 16)
	{
		ft_printhex(n / 16, format, j);
		ft_printhex(n % 16, format, j);
	}
	else
	{	if (n <= 9)//imprime el correspondiente
			ft_putchar(n + '0', j);
		else
		{
			if (format == 'x')
				ft_putchar((n - 10 + 'a'), j);
			if (format == 'X')
				ft_putchar((n - 10 + 'A'), j);
		}
	}
}
int	ft_puthexa(unsigned int n, const char format, int j)//principal
{
	if (n == 0)
		return (write(1,"0", 1));
	ft_printhex(n, format, j);

	return (ft_hexlen(n));
}

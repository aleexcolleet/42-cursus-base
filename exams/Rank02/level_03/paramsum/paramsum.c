#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_small_putnbr(int n)
{
	if (n > 9)
	{
		ft_small_putnbr(n / 10);
		ft_small_putnbr(n % 10);
	}
	else
		ft_putchar(n + '0');
}

int main(int as, char **av)
{
	(void)av;
	ft_small_putnbr(as - 1);
	ft_putchar('\n');
	return (0);
}

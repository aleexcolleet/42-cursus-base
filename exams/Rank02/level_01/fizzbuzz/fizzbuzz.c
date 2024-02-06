#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}
void	ft_putnbr(int nbr)
{
	if (nbr > 9)
	{
		ft_putnbr(nbr % 10);
		ft_putnbr(nbr / 10);
	}
	else
		ft_putchar(nbr + '0');
}

void	fizzbuzz()
{
	int number;

	number = 1;
	while (number <= 100)
	{
		if (((number % 3) == 0) && ((number % 5) == 0))
		{
			write(1, "fizzbuzz", 8);
			number++;
			ft_putchar('\n');
		}
		if ((number % 3) == 0)
		{
			write(1, "fizz", 4);
			number++;
			ft_putchar('\n');
		}
		if ((number % 5) == 0)
		{
			write(1, "buzz", 4);
			number++;
			ft_putchar('\n');
		}
		else
		{
			ft_putnbr(number);
			ft_putchar('\n');
		}
		number++;
	}
}
int main(void)
{
	fizzbuzz();
	return (0);
}

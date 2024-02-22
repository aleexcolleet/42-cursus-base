#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_put_nbr(int nbr)
{
	if (nbr > 10)
	{
		ft_put_nbr(nbr / 10);
		ft_put_nbr(nbr % 10);
	}
	else
		ft_putchar(nbr + '0');
}

void	ft_putstr(char *c)
{
	int i;

	i = 0;
	while (c[i])
	{
		write(1, &c[i], 1);
		i++;
	}
}

void	tab_mult(int nbr)
{
	int i;
	int res;

	i = 1;
	while (i < 10)
	{
		res = i * nbr;
		ft_put_nbr(i);
		ft_putstr(" x ");
		ft_put_nbr(nbr);
		ft_putstr(" = ");
		ft_put_nbr(res);
		ft_putchar('\n');
		i++;
	}
}

int main(void)
{
	int nbr;

	printf("display a number:\n");
	scanf("%d", &nbr);
	tab_mult(nbr);
	return (0);
}

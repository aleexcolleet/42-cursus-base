#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_put_nbr(int nbr)
{
	if (nbr > 9)
	{
		ft_put_nbr(nbr / 10);
		ft_put_nbr(nbr % 10);
	}
	else
	{
		ft_putchar(nbr + '0');
	}
}

int ft_short_atoi(char *str)
{
	int i;
	int nbr;

	nbr = 0;
	i = 0;
	while (str[i])
	{
		nbr = (nbr * 10) + (str[i] - '0');
		i++;
	}
	return (nbr);
}

int ft_is_pr(int nbr)
{
	int check;

	check = 2;
	if (nbr <= 1)
		return (0);
	while (nbr > check)
	{
		if ((nbr % check) == 0)
			return (0);
		check++;
	}
	return (1);
}

int sum_prime(int nbr)
{
	int check;
	int sum;

	sum = 0;
	check = 2;
	if (nbr <= 0)
		return (0);
	while (check <= nbr)
	{
		if (ft_is_pr(check))
			sum += check;
		check++;
	}
	return (sum);
}

int main(int as, char **av)
{
	if (as == 2)
		ft_put_nbr(sum_prime(ft_short_atoi(av[1])));
	ft_putchar('\n');
	return (0);
}

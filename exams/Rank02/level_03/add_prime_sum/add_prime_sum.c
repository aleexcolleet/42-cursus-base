#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	short_atoi(char *str)
{
	int i;
	int res;

	i = 0;
	res = 0;
	while (str[i])
	{
		res *= 10;
		res += str[i] - '0';
		i++;
	}
	return (res);
}

void	ft_small_put_nbr(int nbr)
{
	char digit_char;

	if (nbr > 9)
	{
		ft_small_put_nbr(nbr / 10);
		ft_small_put_nbr(nbr % 10);
	}
	else
	{
		digit_char = nbr + '0';
		write(1, &digit_char, 1);
	}
}

int	ft_is_prime(int nbr)
{
	int check;

	check = 2;
	if (nbr <= 1)
		return (0);
	while (check < nbr)
	{
		if ((nbr % check) == 0)
			return (0);
		check++;
	}
	return (1);
}

int	ft_addP_sum(int n)
{
	int i;
	int sum;

	i = 2;
	sum = 0;
	if (n <= 0)
		return (0);
	while (i <= n)
	{
		if (ft_is_prime(i))
			sum += i;
		i++;
	}
	return (sum);
}


int main(int as, char **av)
{
	if (as == 2)
		ft_small_put_nbr(ft_addP_sum(short_atoi(av[1])));
	ft_putchar('\n');
	return (0);
}

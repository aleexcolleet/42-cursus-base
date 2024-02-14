#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
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

void	ft_addP(unsigned int n)
{
	int i;
	int sum;

	i = 2;
	sum = 0;
	while (i <= n)
	{
		if (ft_is_prime(n))
			sum += i;
		i++;
	}
	return (sum);
}


int main(int as, char **av)
{
	if (as == 2 && av[1] >= 0)
		ft_addP(av[1])
	ft_putchar('\0');
	return (0);
}

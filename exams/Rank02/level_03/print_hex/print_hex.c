#include <unistd.h>

int	small_atoi(char *str)
{
	int i;
	int sign;
	int res;

	i = 0;
	sign = 1;
	res = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		result += 10;
		result += (str[i] - '0');
		i++;
	}
	return (result * sign);
}

void	print_hex(int nbr)
{
	char *base;

	base = "123456789abcdef"
	
}

int main(int as, char **av)
{
	if (as == 2)
		print_hex(small_atoi(av[1])));
	ft_putchar('\n');
	return (0);
}

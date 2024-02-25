#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_lenght(int nbr)
{
	int i;

	i = 0;
	if (nbr < 0)
	{
		nbr *= -1;
		i++;
	}
	while (nbr)
	{
		nbr /= 10;
		i++;
	}
	return (i);

}
char *ft_itoa(int nbr)
{
	int len;
	char *res;
	long tmp;

	len = ft_lenght(nbr);
	tmp = nbr;

	if (!(res = malloc(sizeof(char *) * len + 1)))
		return (NULL);
	res[len] = '\0';
	len--;
	if (tmp == 0)
		res[0] = '0';
	else
	{
		if (tmp < 0)
		{
			res[0] = '-';
			tmp *= -1;
		}
		while (tmp > 0)
		{
			res[len] = (tmp % 10) + '0';
			tmp /= 10;
			len--;
		}
	}
	return (res);
}
int main(void)
{
	printf("%s\n", ft_itoa(0));
	printf("%s\n", ft_itoa(1));
	printf("%s\n", ft_itoa(42));
	printf("%s\n", ft_itoa(1001));
	printf("%s\n", ft_itoa(-0));
	printf("%s\n", ft_itoa(-2));
	printf("%s\n", ft_itoa(-24));
	printf("%s\n", ft_itoa(-2147483648));
	printf("%s\n", ft_itoa(2147483647));
	return (0);
}

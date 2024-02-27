#include <stdio.h>
#include <stdlib.h>

int	ft_len(int nbr)
{
	int i;

	i = 0;
	if (nbr < 0)
	{
		i++;
		nbr *= -1;
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
	char *new;
	if (!nbr)
		return ("0");
	if (nbr == -2147483648)
		return ("-2147483648");
	len = ft_len(nbr);
	new = (char *)malloc(sizeof(char) * len + 1);
	if (!new)
		return (NULL);
	if (nbr < 0)
	{
		new[0] = '-';
		nbr *= -1;
	}
	new[len--] = 0;
	while (nbr)
	{
		new[len] = (nbr % 10) + '0';
		nbr /= 10;
		len--;
	}
	return (new);
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

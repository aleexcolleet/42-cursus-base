#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	ft_size(int nbr)
{
	int i;

	i = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		i++;
		nbr *= -1;
	}
	while (nbr > 0)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}

char *ft_itoa(int nbr)
{
	char *res;
	int len;

	if (nbr == 0)
		return (NULL);
	if (nbr <= -2147483648)
		return ("-214783648\0");
	len = ft_size(nbr);
	res = (char *)malloc(sizeof(char) * len + 1);
	if (!res)
		return (NULL);
	res[len] = '\0';
	if (nbr < 0)
	{
		res[0] = '-';
		nbr *= -1;
	}
	while (nbr)
	{
		res[--len] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (res);
}

int main(void)
{
	char *str = ft_itoa(39999);
	printf("res--> %s", str);
	free(str);
	return (0);
}

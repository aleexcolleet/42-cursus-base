#include "ft_printf.h"

int	ft_numlen(unsigned int n)
{
	int	size;

	size = 0;
	while (n)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char *ft_unsignedfunc(unsigned int n)
{
	char	*conv;
	int		size;

	size = ft_numlen(n);
	conv = (char *)malloc(sizeof(char *) * (size + 1));
	if (!conv)
		return (NULL);
	conv[size] = '\0';
	while (n != 0)
	{
		conv[size - 1] = n % 10 + '0';
		n /= 10;
		size--;
	}
	return (conv);
}

int	ft_unsfunct(unsigned int n, int j)//principal
{
	char *result;
	int	size;

	size = 0;
	if (!n)
	{
		write(1, "0", 1);
		return (j += 1);
	}
	result = ft_unsignedfunc(n);
	size = ft_putstr(result, j);
	free(result);
	return (size);
}

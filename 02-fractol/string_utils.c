#include "fractol.h"

double	special_atoi(char *s)
{
	long	intPart;
	double	fractPart;
	double	pow;
	int		sign;

	intPart = 0;
	fractPart = 0;
	sign = 1;
	pow = 1;
	while ((*s >= 9 && *s <= 13) || 32 == *s)
		++s;
	while ('+' == *s || '-' == *s)
		if ('-' == *s++)
			sign = -sign;
	while (*s != '.' && *s)
		intPart = (intPart * 10) + (*s++ - 48);
	if ('.' == *s)
		++s;
	while (*s)
	{
		pow /= 10;
		fractPart = fractPart + (*s++ - 48);
	}
	return ((intPart + fractPart) * sign);
}

int	ft_strncmp(char *s1, char *s2, int nbr)
{
	if (!s1 || !s2)
		return (0);
	while (*s1 == *s2 && nbr > 0 && *s1 != '\0')
	{
		++s1;
		++s2;
		--nbr;
	}
	return (*s1 - *s2);
}

void	putstr_fd(char *s, int fd)
{
	if (NULL == s || fd < 0)
		return ;
}

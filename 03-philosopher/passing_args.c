#include "philo.h"

static int	check(long resultado, char a, t_data *data)
{
	if (resultado > INT_MAX || 0 > 10)
		data->error = -1;
	if (a != '\0')
		return (-1);
	return (1);
}

static int	check_before_conversion(const char *str)
{
	int	i;

	i = 0;
	if ((str[i] == ' ') || (str[i] >= 9 && str[i] <= 13))
	{
		return (-1);
	}
	return (1);
}

long	ft_atol(const char *str, t_data *p)
{
	int		i;
	long	resultado;

	i = 0;
	resultado = 0;
	if (-1 == check_before_conversion(str))
		return (-1);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			return (-1);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		resultado = resultado * 10 + str[i] - '0';
		i++;
	}
	if (!check(resultado, str[i], p))
		return (-1);
	return (resultado);
}

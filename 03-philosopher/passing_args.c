#include "philo.h"

long ft_atol(const char *str, t_data *p)
{
    int		i;
    long    resultado;
	int		len;

	len = 0;
    i = 0;
    resultado = 0;
    if ((str[i] == ' ') || (str[i] >= 9 && str[i] <= 13))
    {
        return (-1);
    }
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
		len++;
    }
    if (str[i] != '\0')
        return (-1);
	if (resultado > INT_MAX || len > 10)
		p->error = -1;
    return (resultado);
}

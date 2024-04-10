#include "philo.h"

int	ft_atoi(const char *str, t_data *p)
{
    int    i;
    int    resultado;

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
    }
    if (str[i] != '\0')
    {
		printf("There are non accepted characters\n");
        return (-1);
    }
    return (resultado);
}
/*
bool is_al_num(char *str)
{
    while (*str)
	{
        if (!ft_isdigit(*str))
            return (false);
        str++;
    }
    return (true);
 
}


bool verify_args(int as, char **av, t_data *p)
{
	

	

	help_msg();
}*/


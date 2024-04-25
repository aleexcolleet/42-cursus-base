#include "philo.h"

void	error_exit(const char *error)
{
	printf("error-> %s\n", error);
}

void	leaving_safely(t_data *data)
{
	int	i;
	t_philo *philo;

	i = -1;
	while(++i < data->num_philo)
	{
		philo = data->philos + 1;
		safe_mutex_handle(&philo->philo_mutex, DESTROY, data);
	}
	if (data->philos)
	{
		safe_mutex_handle(&data->write_mutex, DESTROY, data);
		safe_mutex_handle(&data->table_mutex, DESTROY, data);
		free(data->forks);
		free(data->philos);
	}
	free(data);
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


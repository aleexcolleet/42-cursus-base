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

//Get time of day ⏱️
//
//time_code -> SECONDS MILLISECONDS MICROSECONDS
//

long	get_time(t_time_code time_code)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		error_exit("Gettimeodday failed");
	if (SECOND == time_code)
		return (tv.tv_sec + (tv.tv_usec / 1e6));
	else if (MILLISECOND == time_code)
		return ((tv.tv_sec * 1e3) + (tv.tv_usec / 1e3));
	else if (MICROSECOND == time_code)
		return ((tv.tv_sec * 1e6) + tv.tv_usec);
	return (1337);	

}

//Precise usleep
/*start registra el tiempo de inicio en microsegundos utilizando la función gettime (no proporcionada en el código, pero se asume que devuelve el tiempo actual en microsegundos).
La función entra en un bucle mientras el tiempo transcurrido desde el inicio es menor que el tiempo deseado (usec). Dentro del bucle, se verifica si la simulación ha terminado llamando a la función simulation_finished.
Se calcula el tiempo transcurrido (elapsed) y el tiempo restante (rem) para cumplir con el tiempo total deseado (usec).
Si el tiempo restante (rem) es mayor que 10,000 microsegundos (0.01 segundos), la función llama a usleep para dormir durante la mitad del tiempo restante (rem / 2). Esto se hace para evitar esperas ocupadas innecesarias cuando el tiempo restante es grande.
Si el tiempo restante es menor o igual a 10,000 microsegundos, la función entra en un bucle de espera ocupada (while) hasta que se haya alcanzado el tiempo deseado (usec). Esta espera ocupada proporciona una mayor precisión en períodos de tiempo más cortos.
*/


void	precise_usleep(long usec, t_data *data)
{

	long	start;
	long	elapsed;
	long	rem;

	start = get_time(MICROSECOND);
	while (get_time(MICROSECOND) - start < usec)
	{
		if (simulation_finished(data))
			break ;
		elapsed = get_time(MICROSECOND) - start;
		rem = usec - elapsed;
		if (rem > 1e4)
			usleep(rem / 2);
		else
			while (get_time(MICROSECOND) - start < usec)
				;
	}
}

//make the sistem fair
void de_shyncronize_philos(t_philo *philo)
{
	if (philo->data->num_philo % 2 == 0)
	{
		if (philo->id % 2 == 0)
			precise_usleep(3e4, philo->data);
	}
	else
	{
		if (philo->id % 2)
			thinking(philo, philo->data, true);
	}
}

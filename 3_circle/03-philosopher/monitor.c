#include "philo.h"

static bool	philo_died(t_philo *philo, t_data *data)
{
	long	elapsed;
	long	t_to_die;

	if (get_bool(&philo->philo_mutex, &philo->full, data))
		return (false);
	elapsed = get_time(MILLISECOND) - get_long(&philo->philo_mutex,
			&philo->last_meal_time, data);
	t_to_die = philo->data->time_to_die / 1e3;
	if (elapsed > t_to_die)
		return (true);
	return (false);
}

//spinlock till all threads running
//it is basically checking all philosophers
//if elapsed time is bigger than time to die,
//then the philosopher is dead. END the simulation
void	*monitor_dinner(void *data)
{
	int		i;
	t_data	*tmp_data;

	tmp_data = (t_data *)data;
	while (!all_threads_running(&tmp_data->table_mutex,
			&tmp_data->threads_running_nbr, tmp_data->num_philo, data))
		;
	while (!simulation_finished(tmp_data))
	{
		i = -1;
		while (++i < tmp_data->num_philo && !simulation_finished(tmp_data))
		{
			if (philo_died(tmp_data->philos + i, data))
			{
				set_bool(&tmp_data->table_mutex,
					&tmp_data->end_simulation, true, data);
				write_status(DIED, tmp_data->philos + i, data);
			}
		}
	}
	return (NULL);
}
//monitor waits untill all all_thrads are 

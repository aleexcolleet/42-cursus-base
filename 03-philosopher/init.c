#include "philo.h"

//philo positiona already calculated when passing i from the other function
//left fork positions does need to be calculated
//even odd fork assignement
static void	assigning_forks(t_philo *philo, t_fork *forks, int position)
{
	int	philo_nbr;

	philo_nbr = philo->data->num_philo;
	philo->first_fork = &forks[(position + 1) % philo_nbr];
	philo->second_fork = &forks[position];
	if (philo->id % 2 == 0)
	{
		philo->first_fork = &forks[position];
		philo->second_fork = &forks[(position + 1) % philo_nbr];
	}
}

static void	philosophers_init(t_data *data)
{
	int		i;
	t_philo	*philo;

	i = -1;
	while (++i < data->num_philo)
	{
		philo = data->philos + i;
		philo->id = i + 1;
		philo->full = false;
		philo->meals_counter = 0;
		safe_mutex_handle(&philo->philo_mutex, INIT, data);
		philo->data = data;
		assigning_forks(philo, data->forks, i);
	}
}

int	init_structure(t_data *data)
{
	int	y;

	y = -1;
	data->end_simulation = false;
	data->all_threads_ready = false;
	data->threads_running_nbr = 0;
	if (data->num_philo < 0)
	{
		help_msg();
		return (2);
	}
	data->philos = safe_malloc(data->num_philo * sizeof(t_philo), data);
	data->forks = safe_malloc(data->num_philo * sizeof(t_fork), data);
	safe_mutex_handle(&data->write_mutex, INIT, data);
	safe_mutex_handle(&data->table_mutex, INIT, data);
	while (++y < data->num_philo)
	{
		safe_mutex_handle(&data->forks[y].fork, INIT, data);
		data->forks[y].fork_id = y;
	}
	philosophers_init(data);
	return (0);
}

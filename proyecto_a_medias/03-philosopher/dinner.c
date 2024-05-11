#include "philo.h"

static void	thinking(t_philo *philo, t_data *data)
{
	write_status(THINKING, philo, data);
}

/*
 * eat routine
 * 1) grab the forks: here first & second fork is handy
 *		i don't worry about left right
 *	2) eat: write eat, update last meal and meals counter
 *		eventually bool full
 *	3) release the forks
 */
static void	eat(t_philo *philo, t_data *data)
{
	safe_mutex_handle(&philo->first_fork->fork, LOCK, data);
	write_status(TAKE_FIRST_FORK, philo, data);
	safe_mutex_handle(&philo->second_fork->fork, LOCK, data);
	write_status(TAKE_SECOND_FORK, philo, data);

	set_long(&philo->philo_mutex, &philo->last_meal_time,
		  get_time(MILLISECOND), data);
	philo->meals_counter++;
	write_status(EATING, philo, data);
	precise_usleep(philo->data->time_to_eat, data);
	if (philo->data->how_many_meals > 0
		&& philo->meals_counter == philo->data->how_many_meals)
		set_bool(&philo->philo_mutex, &philo->full, true, data);

	safe_mutex_handle(&philo->first_fork->fork, UNLOCK, data);
	safe_mutex_handle(&philo->first_fork->fork, UNLOCK, data);
}

/*
*	1_ wait all philos, then synchro starts
*	2_ endless loop philo
*/
void	*dinner_simulation(void *data)
{
	t_philo *philo;

	philo = (t_philo *)data;
	waiting_all_threads(philo->data);

	//set last meal time
	while (!simulation_finished(philo->data))
	{
		if (philo->full) //TODO thread safe
			break;
		eat(philo, data);
		//sleeping : write_status & precise usleep✅
	write_status(SLEEPING, philo, data);
	precise_usleep(philo->data->time_to_sleep, philo->data);
		thinking(philo, data);
	}
	return (NULL);
}

//ACTUAL STUFF OF THE PROJECT
//
// - if no meals -->[0]
//		only one philo-> ad hoc function
//1_ Create all threads, all philos
//2_ create a monitor thread ->☠️
//3_ Syncronize the beggining of the simulation
//		when pthread_create -> philo starts running!
//			we need em to start simultaneously
//4_ JOIN everyone
//

int	dinner_must_beggin(t_data *data)
{
	int	i;

	i = -1;
	if (0 == data->how_many_meals)
		return (0);
//	else if (1 == data->num_philo) TODO		
	else
		while(++i < data->num_philo)
			if (0 > safe_thread_handle(&data->philos[i].thread_id, dinner_simulation, &data->philos[i], CREATE))
				return (-1);
	//BEGGIN THE simulation
	data->start_simulation = get_time(MILLISECOND);
	//now all threads are ready
	set_bool(&data->table_mutex, &data->all_threads_ready, true, data);
	i = -1;
	while (++i < data->num_philo)
		if (0 > safe_thread_handle(&data->philos[i].thread_id, NULL, NULL, JOIN))
		{
			data->error = 2;
			error_exit("thread managing error\n");
			return (2);
		}
	set_bool(&data->table_mutex, &data->end_simulation, true, data);
	safe_thread_handle(&data->monitor, NULL, NULL, JOIN);
	return (0);
}

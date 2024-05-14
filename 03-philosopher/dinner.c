#include "philo.h"

//here we trying to make the slower philo get an odd to 
//take forks before others that haven't thinked as much.
//We make this last start to think arbitrary.
void	thinking(t_philo *philo, t_data *data, bool pre_simulation)
{
	long	t_eat;
	long	t_sleep;
	long	t_think;

	if (!pre_simulation)
		write_status(THINKING, philo, philo->data);
	write_status(THINKING, philo, data);
	if  (philo->data->num_philo % 2 == 0)
		return ;
	t_eat = philo->data->time_to_eat;
	t_sleep = philo->data->time_to_sleep;
	t_think = t_eat * 2 - t_sleep;
	if (t_think < 0)
		t_think = 0;
	precise_usleep(t_think * 0.42, philo->data);

}

//1) fake to lock the fork
//2)Sleep unitl the monitor will bust it
//
//so basically as the last meal time is never
//going to be updated, it just sleeps until finish.
void *lone_philo(void *arg)
{
	t_philo *philo;
	t_data *data;

	data = 0;
	philo = (t_philo *)arg;
	waiting_all_threads(philo->data);
	set_long(&philo->philo_mutex, &philo->last_meal_time, get_time(MILLISECOND), data);
	increase_long(&philo->data->table_mutex, &philo->data->threads_running_nbr, data);
	write_status(TAKE_FIRST_FORK, philo, data);
	while (!simulation_finished(philo->data))
		usleep(200);
	return (NULL);

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
	precise_usleep(philo->data->time_to_eat, philo->data);
	if (philo->data->how_many_meals > 0
		&& philo->meals_counter == philo->data->how_many_meals)
		set_bool(&philo->philo_mutex, &philo->full, true, data);
	safe_mutex_handle(&philo->first_fork->fork, UNLOCK, data);
	safe_mutex_handle(&philo->second_fork->fork, UNLOCK, data);
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

	set_long(&philo->philo_mutex, &philo->last_meal_time,
		  get_time(MILLISECOND), data);
	//set time last meal
	increase_long(&philo->data->table_mutex,
				&philo->data->threads_running_nbr, data);

	//in order to get a fair job, meaning the same philo
	//doesn't eat two times, consequently ending the program. 
	//We need to impose an arbitrary solution for odd num of philos.
	//So, we desynchronize philos before the actual loop.
	de_shyncronize_philos(philo);
	while (!simulation_finished(philo->data))
	{
		if (philo->full) //TODO thread safe
			break;
		eat(philo, data);
		write_status(SLEEPING, philo, data);
		precise_usleep(philo->data->time_to_sleep, philo->data);
		thinking(philo, data, false); //todo
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
	else if (1 == data->num_philo)
		safe_thread_handle(&data->philos[0].thread_id, lone_philo, &data->philos[0], CREATE);
	else
	{	
		while(++i < data->num_philo)
			if (0 > safe_thread_handle(&data->philos[i].thread_id,
								 dinner_simulation, &data->philos[i], CREATE))
				return (-1);
	}
	//MONITOR 💀
	safe_thread_handle(&data->monitor, monitor_dinner, data, CREATE); //TODO
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

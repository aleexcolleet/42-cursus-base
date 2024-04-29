#include "philo.h"

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
	//	eat(philo); //TODO
		//sleeping : write_status & precise usleep✅
	write_status(SLEEPING, philo, DEBUG_MODE);
	precise_usleep(philo->data->time_to_sleep, philo->data);
	//	thinking(philo); //TODO
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

	i = 0;
	if (0 == data->how_many_meals)
		return (0);
//	else if (1 == data->num_philo)
//		;//TODO
	else
		while(++i < data->num_philo)
			if (0 > safe_thread_handle(&data->philos[i].thread_id,
							  dinner_simulation, &data->philos[i], CREATE))
				return (-1);

	//BEGGIN THE simulation
	data->start_simulation = get_time(MILLISECOND);
	//now all threads are ready
	set_bool(&data->table_mutex, &data->all_threads_ready, true, data);

	i = -1;
	while (++i < data->num_philo)
		safe_thread_handle(&data->philos[i].thread_id, NULL, NULL, JOIN);
	//if we manage to reach this line, all philos are FULL;
	
	
	

	return (0);
}

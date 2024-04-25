#include "philo.h"

/*
*	1_ wait all philos, then synchro starts
*	2_ endless loop philo
*/
void	*dinner_simulation(void *data)
{
	t_philo *philo;

	philo = (t_philo *)data;
	waiting_for_all_threads(philo->table);

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
void	dinner_must_beggin(t_data *data)
{
	int	i;

	i = 0;
	if (0 == data->how_many_meals)
		return;
	else if (1 == data->num_philo)
		;//TODO
	else
		while(++i < data->num_philo)
			safe_thread_handle(&data->philos[i].thread_id,
				dinner_simulation, &data->philo[i], CREATE);
	//now all threads have been made
		
}

#include "philo.h"

//same as write but useful for debugging. Gotta change the constant debug mode 0
/*
*	[time_ms] [philo_id] [action]
*	thread safe
*		write mutex
*/

void	write_status(t_philo_status status, t_philo *philo, t_data *data)
{
	long	elapsed;

	elapsed = get_time(MILLISECOND) - philo->data->start_simulation;
	if (get_bool(&philo->philo_mutex, &philo->full, philo->data))
		return ;
	safe_mutex_handle(&philo->data->write_mutex, LOCK, data);
	
	if ((TAKE_FIRST_FORK == status || TAKE_SECOND_FORK == status)
		&& !simulation_finished(philo->data))
		printf("%-6ld %d has taken a fork\n", elapsed, philo->id);
	else if (EATING == status && !simulation_finished(philo->data))
		printf("%-6ld %d is eating\n", elapsed, philo->id);
	else if (SLEEPING == status && !simulation_finished(philo->data))
		printf("%-6ld %d is sleeping\n", elapsed, philo->id);
	else if (THINKING == status && !simulation_finished(philo->data))
		printf("%-6ld %d is thinking\n", elapsed, philo->id);
	else if (DIED == status)
		printf("%-6ld %d died\n", elapsed, philo->id);
	safe_mutex_handle(&philo->data->write_mutex, UNLOCK, data);
}

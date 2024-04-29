#include "philo.h"

//same as write but useful for debugging. Gotta change the constant debug mode 0
/*
*	[time_ms] [philo_id] [action]
*	thread safe
*		write mutex
*/

void write_status(t_philo_status status, t_philo *philo)
{
	long	elapsed;

	elapsed = get_time(MILLISECONDS) - philo->data->start_simulation;
	if (philo->full)
		return ;
	safe_mutex_handle(&philo->data->write_mutex, LOCK);
	else
	{
		if ((TAKE_FIRST_FORK == status || TAKE_SECOND_FORK == status)
			&& !simulation_finished(philo->data)
			printf("%-6ld "RST" %d has taken a fork\n", elapsed, philo->id);
		else if (EATING == status && !simulation_finished(philo->data))
			printf("%-6ld"RST" %d is sleeping\n", elased, philo->id);
		else if (SLEEPING == status && !simulation_finished(philo->data))
			printf("%-6ld"RST" %d is sleeping\n", elapsed, philo->id);
		else if (THINKING == status && !simulation_finished(philo->data))
			printf("%-6ld"RST" %d is thinking\n", elapsed, philo->id);
		else if (DIED == status)
			printf(RED"%-6ld %d died\n"RST, elapsed, philo->id);
	}
	safe_mutex_handle(&philo->data->write_mutex, UNLOCK);

}

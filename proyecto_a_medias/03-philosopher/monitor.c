#include "philo.h"

//spinlock till all threads running
void	*monitor_dinner(void *data)
{
	t_data *data;
	data = (t_data *)data;
	while (!all_threads_running(&data->table_mutex, &data->threads_running_nbr, data->philo_nbr))//TODO
		;
		return (NULL);
	while (!simulation_finished(data))
	{

	}
}

//monitor waits untill all all_thrads are 

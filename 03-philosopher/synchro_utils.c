#include "philo.h"

//waiting for all threads to be ready
//technically SPINLOCK to Synchronize philos start
void	waiting_all_threads(t_data *data)
{
	while (!get_bool(&data->table_mutex, &data->all_threads_ready, data))
		;
}

bool	all_threads_running(t_mtx *mutex, long *threads,
		long philo_nbr, t_data *data)
{
	bool	ret;
	
	ret = false;
	safe_mutex_handle(mutex, LOCK, data);
	if (*threads == philo_nbr)
		ret = true;
	safe_mutex_handle(mutex, UNLOCK, data);
	return (ret);
}

//this increases threads running to 
//synchro with the monitor
void	increase_long(t_mtx *mutex, long *value, t_data *data)
{
	safe_mutex_handle(mutex, LOCK, data);
	(*value)++;
	safe_mutex_handle(mutex, UNLOCK, data);
}

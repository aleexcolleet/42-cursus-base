#include "philo.h"

/*
* To avoid writting LOCK UNLOCK everywhere
*/

//BOOL managing

void	set_bool(t_mtx *mutex, bool *dest, bool value, t_data *data)
{
	safe_mutex_handle(mutex, LOCK, data);
	*dest = value;
	safe_mutex_handle(mutex, UNLOCK, data);
}

bool	get_bool(t_mtx *mutex, bool *value, t_data *data)
{
	bool	ret;

	safe_mutex_handle(mutex, LOCK, data);
	ret = *value;
	safe_mutex_handle(mutex, UNLOCK, data);
	return (ret);
}

long	get_long(t_mtx *mutex, long *value, t_data *data)
{
	long	ret;

	safe_mutex_handle(mutex, LOCK, data);
	ret = *value;
	safe_mutex_handle(mutex, UNLOCK, data);
	return (ret);
}

void	set_long(t_mtx *mutex, long *dest, long value, t_data *data)
{
	safe_mutex_handle(mutex, LOCK, data);
	*dest = value;
	safe_mutex_handle(mutex, UNLOCK, data);
}

bool	simulation_finished(t_data *data)
{
	return (get_bool(&data->table_mutex, &data->end_simulation, data));
}

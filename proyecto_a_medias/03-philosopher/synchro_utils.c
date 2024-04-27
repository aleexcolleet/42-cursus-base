#include "philo.h"

//waiting for all threads to be ready
void	waiting_all_threads(t_data *data)
{
	while (!get_bool(&data->table_mutex, &data->all_threads_ready))
		;
}

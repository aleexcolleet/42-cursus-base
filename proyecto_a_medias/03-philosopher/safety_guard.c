#include "philo.h"

void	*safe_malloc(size_t bytes, t_data *data)
{
	void	*ret;

	ret = malloc(bytes);
	if (!ret)
	{
		printf("Error with the malloc\n");
		data->error = -2;
		return (NULL);
	}
	return (ret);
}

//status == 0 --> everything is correct
static void	handle_mutex_error(int status, t_opcode opcode, t_data *data)
{
	int i;

	i = 0;
	if (0 == status)
		return ;
	else if (EINVAL == status && (LOCK == opcode || UNLOCK == opcode))
		error_exit("The value specified by mutex is invalid.\n");
	else if (EINVAL == status && INIT == opcode)
		error_exit("The value specified by attr is invalid\n");
	else if (EDEADLK == status)
		error_exit("A deadock would occur if the thread blocked waiting for mutex\n");
	else if (EPERM == status)
		error_exit("The current thread does not hold a lock on mutex\n");
	else if (ENOMEM == status)
		error_exit("The procces cannoc allocate enought memory to create another mutex\n");
	else if (EBUSY == status)
		error_exit("Mutex is locked\n");
	else
		i = 1;
	if (!i)
		data->error = -3;
}

// MUTEX SAFE //
// Init Destroy Lock Unlock
//
//I'm using a OPCODE enum to indicate my program
//what to do in each situation. That way code
//is more readeble
void	safe_mutex_handle(t_mtx *mutex, t_opcode opcode, t_data *data)
{
	if (LOCK == opcode)
		handle_mutex_error(pthread_mutex_lock(mutex), opcode, data);
	else if (UNLOCK == opcode)
		handle_mutex_error(pthread_mutex_unlock(mutex), opcode, data);
	else if (INIT == opcode)
		handle_mutex_error(pthread_mutex_init(mutex, NULL), opcode, data);
	else if (DESTROY == opcode)
		handle_mutex_error(pthread_mutex_destroy(mutex), opcode, data);
	else
	{
		printf("Wrong opcode for mutex\n");
		data->error = -3;
		return;
	}
}

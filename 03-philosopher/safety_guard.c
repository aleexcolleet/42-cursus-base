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

//if there is succes, all mutex and thread functons will
//return zero, otherwise an error number specified.
static void	handle_mutex_error(int status, t_opcode opcode, t_data *data)
{
	int	i;

	i = 0;
	if (0 == status)
		return ;
	if (EINVAL == status && (LOCK == opcode || UNLOCK == opcode))
		error_exit("The value specified by mutex is invalid.\n");
	else if (EINVAL == status && INIT == opcode)
		error_exit("The value specified by attr is invalid\n");
	else if (EDEADLK == status)
		error_exit("A deadock would occur if the thread blocked\n");
	else if (EPERM == status)
		error_exit("The current thread does not hold a lock on mutex\n");
	else if (ENOMEM == status)
		error_exit("The procces cannoc allocate enought memory for mutex\n");
	else if (EBUSY == status)
		error_exit("Mutex is locked\n");
	else
		i = 1;
	if (0 == i)
		data->error = -3;
}
//thread errors

static void	handle_thread_error(int status, t_opcode opcode)
{
	if (0 == status)
		return ;
	if (EAGAIN == status)
		error_exit("No resources to create another thread");
	else if (EPERM == status)
		error_exit("The caller does not have appropriate permission\n");
	else if (EINVAL == status && CREATE == opcode)
		error_exit("The value specified by attr is invalid.");
	else if (EINVAL == status && (JOIN == opcode || DETACH == opcode))
		error_exit("The value specified by thread is not joinable\n");
	else if (ESRCH == status)
		error_exit("No thread could be found corresponding to that"
			"specified by the given thread ID, thread.");
	else if (EDEADLK == status)
		error_exit("A deadlock was detected or the value of"
			"thread specifies the calling thread.");
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
		return ;
	}
}

int	safe_thread_handle(pthread_t *thread, void *(*foo)(void *),
		void *data, t_opcode opcode)
{
	if (CREATE == opcode)
		handle_thread_error(pthread_create(thread, NULL, foo, data), opcode);
	else if (JOIN == opcode)
		handle_thread_error(pthread_join(*thread, NULL), opcode);
	else if (DETACH == opcode)
		handle_thread_error(pthread_detach(*thread), opcode);
	else
	{
		error_exit("Wrong opcode for thread_handle:"
			" use <CREATE> <JOIN> <DETACH>");
		return (-1);
	}
	return (0);
}

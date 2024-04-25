#ifndef PHILO_H
# define PHILO_H

//FALTA
//Passar de atoi a atol para que sea long
//proteger limits (int max)

//sources ---> forks
//threads ---> philosophers
# include <stdio.h> //printf
# include <unistd.h> 
# include <stdlib.h> //malloc
# include <string.h>
# include <stdbool.h>
# include <pthread.h> //mutex & threads managing
# include <sys/time.h> //gettimeofday
# include <limits.h>
# include <errno.h> //for errors managing

# ifndef DEBUG_MODE
#  define DEBUG_MODE 0
# endif

typedef enum e_status
{
	EATING,
	SLEEPING,
	THINKING,
	TAKE_FIRST_FORK,
	TAKE_SECOND_FORK,
	DIED,
}			t_philo_status;



//ENUM OPCODE
//
typedef enum e_opcode
{
	LOCK,
	UNLOCK,
	INIT,
	DESTROY,
	CREATE,
	JOIN,
	DETACH,
}	t_opcode;

typedef pthread_mutex_t t_mtx;
typedef struct s_data t_data;

//FORK STRUCT
typedef struct s_fork
{
	t_mtx	fork;
	int		fork_id;

}				t_fork;

typedef struct s_philo
{
	int				id;
	bool			full; //to know if all meals have been acomplished
	long			meals_counter;
	long			last_meal_time;
	int				last_time_ate; //to check if philo has died
	pthread_t		thread_id;
	t_fork			*first_fork;
	t_fork			*second_fork;
	t_mtx			philo_mutex;
	t_data			*data;

}	t_philo;

struct s_data
{
	t_mtx	table_mutex;
	t_mtx	write_mutex;
	pthread_t	monitor;

	//struct s_list *next;
	long	num_philo;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	how_many_meals;
	long	start_simulation;
	bool	end_simulation;
	bool	all_threads_ready;
	long	threads_running_nbr;
	int		error;
	t_fork	*forks;
	t_philo	*philos;

};

void	help_params(void);
void	*ft_calloc(size_t count, size_t size);
void	*ft_calloc(size_t num_elements, size_t element_size);
void	help_msg(int i);
long	ft_atol(const char *str, t_data *p);

//SAFETY_GUARD
//
void	*safe_malloc(size_t bytes, t_data *data);
//INIT and safe functions
//
void	init_structure(t_data *data);
void	safe_mutex_handle(t_mtx *mutex, t_opcode opcode, t_data *data);

//Philo_utils
void	error_exit(const char *error);
void	leaving_safely(t_data *data);

# endif

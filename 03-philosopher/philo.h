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
# include <pthread.h> //mutex & threads
# include <sys/time.h> //gettimeofday
# include <limits.h>

typedef pthread_mutex_t t_mtx;

//FORK STRUCT
typedef struct s_fork
{
	t_mtx	fork;
	int		fork_id;

}				t_fork;

typedef struct s_philo
{
	int	last_time_ate;

}	t_philo;

typedef struct t_data
{
	t_philo *philo;
	//struct s_list *next;
	long	num_philo;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	how_many_eats;
	int error;
	int id;
	long meals_counter;
	bool full; //to know if all meals have been acomplished
	long last_meal_time; //to check if philo has died
	t_fork *left_fork;
	t_fork *right_fork;


}	t_data;

void	help_params(void);
void	*ft_calloc(size_t count, size_t size);
void	*ft_calloc(size_t num_elements, size_t element_size);
void	help_msg(size_t i, t_data *p);
long	ft_atol(const char *str, t_data *p);
# endif

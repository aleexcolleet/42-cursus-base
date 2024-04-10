#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_data
{
	//struct s_list *next;
	int	num_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	how_many_eats;
	int error;

}	t_data;

void	help_params(void);
void	*ft_calloc(size_t count, size_t size);
void	init_structure(int as, char **av, t_data *p);
void *ft_calloc(size_t num_elements, size_t element_size);
int	ft_atoi(const char *str, t_data *p);
void	help_msg(size_t i, t_data *p);
# endif

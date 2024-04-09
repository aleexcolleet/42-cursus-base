#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_data
{
	struct s_list *next;
	int	num_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	how_many_eats;

}	t_data;

void	help_msg(size_t i);
void	help_params(void);
void	init_structure(t_data *p);
void *ft_calloc(size_t num_elements, size_t element_size);

# endif

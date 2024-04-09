#include "philo.h"

void	init_structure(int as, char **av, t_data *p)
{
	p = ft_calloc(1, sizeof(t_data));
	p->num_philo = ft_atoi(av[1]);
	p->time_to_die = ft_atoi(av[2]);
	p->time_to_eat = ft_atoi(av[3]);
	p->time_to_sleep = ft_atoi(av[4]);
	p->how_many_eats = ft_atoi(av[5]);
}

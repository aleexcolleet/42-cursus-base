#include "philo.h"

void	init_structure(int as, char **av, t_data *p)
{
	p->num_philo = ft_atoi(av[1], p);
	p->time_to_die = ft_atoi(av[2], p);
	p->time_to_eat = ft_atoi(av[3], p);
	p->time_to_sleep = ft_atoi(av[4], p);
	if (as == 6)
		p->how_many_eats = ft_atoi(av[5], p);
	else
		p->how_many_eats = 0;
	if (p->error == -1)
	{	
		help_msg(-1, p);
		return ;
	}
}

#include "philo.h"

static void	passing_args(int as, char **av, t_data *p)
{
	p->error = 0;
	p->num_philo = ft_atol(av[1], p);
	p->time_to_die = ft_atol(av[2], p) * 1e3;
	p->time_to_eat = ft_atol(av[3], p) * 1e3;
	p->time_to_sleep = ft_atol(av[4], p) * 1e3;
	if (p->time_to_die < 6e4
		|| p->time_to_eat < 6e4
		|| p->time_to_sleep < 6e4)
		p->error = -1;
	if (as == 6)
		p->how_many_eats = ft_atol(av[5], p);
	else
		p->how_many_eats = -1;
}

//args (number of philosophers)(time to die)(time_to_sleep) *opcional(time each philo must eat)
//
//Red
//all args must be numeric
//check for INT_MAX
//check if I need to take all args with split
//
/* INPUT 
 * [0] ./philo
 * [1] number_of_philosophers
 * [2] time_to_die
 * [3] time_to_eat
 * [4] time_to_sleep
 * [5] [number_of_times_each_philosopher_must_eat]
*/
int	main(int as, char **av)
{
	t_data *p;

	if (as < 5 || as > 6)
	{
		help_msg(-1);
		return (2);
	}
	p = malloc(sizeof(t_data));
	if (!p)
		return (2);
	passing_args(as, av, p);
	if (p->error == -1)
	{
		help_msg(-1);
		free(p); //falta arreglar
		return (2);
	}

	//if (!verify_args(as, &av, &p));
	//	return (2);
	free(p);	
	return (0);
}

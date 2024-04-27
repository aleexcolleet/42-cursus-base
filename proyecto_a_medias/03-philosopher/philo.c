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
		p->how_many_meals = ft_atol(av[5], p);
	else
		p->how_many_meals = -1;
}

//args (number of philosophers)(time to die)(time_to_sleep) *opcional(time each philo must eat)
//
//Red
//all args must be numeric
//check for INT_MAX
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
	t_data *data;

	if (as < 5 || as > 6)
	{
		help_msg(-1);
		return (2);
	}
	data = malloc(sizeof(t_data));
	if (!data)
		return (2);
	passing_args(as, av, data);
	init_structure(data);
	if (data->error == -1)
	{
		help_msg(-1);
		leaving_safely(data); //falta arreglar
		return (2);
	}
	dinner_must_beggin(data);
	leaving_safely(data);
	return (0);
}

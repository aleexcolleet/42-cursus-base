#include "philo.h"

//args (number of philosophers)(time to die)(time_to_sleep) *opcional(time each philo must eat)
//
//all args must be numeric
int	main(int as, char **av)
{
	t_data *p;
	
	if (as < 5 || as > 6)
	{
		help_msg(-1, p);
		free(p);
		return (2);
	}
	init_structure(as, av, p);
	//if (!verify_args(as, &av, &p));
	//	return (2);
	free(p);	
	return (0);
}

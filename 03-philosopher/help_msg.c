#include "philo.h"
/*
void	clean_exit(t_data *p)
{
	free(p);
}
*/
void	help_params(void)
{
	printf("Params must be:\n\n");
	printf("\033[1;36m");
	printf("./philosophers (num of philosophers) (time to die)\n");
	printf("\t(time to eat) (time to sleep)\n");
	printf("\033[33m");
	printf("\t+ optional---> (number of times each philosopher must eat\n");
	printf("\t in order to end the simulation succesfully\n");
	printf("\033[0m");
}

void	help_msg(size_t i, t_data *p)
{
	printf("\n+--------------------------------------------------+\n");
	printf("	PHILOSOPHERS HELP SHEET\n");
	printf("+--------------------------------------------------+\n\n");
	
	if (-1 == i)
		help_params();
	//clean_exit(p); //TODO
}

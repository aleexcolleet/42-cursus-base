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
	printf("./philo (num of philosophers) (time to die)\n");
	printf("\t(time to eat) (time to sleep)\n");
	printf("\033[33m");
	printf("\t+ optional---> (number of times each philosopher must eat\n");
	printf("\t in order to end the simulation succesfully\n");
	printf("\033[0m");
	printf("\n----------------------------------------------------\n");
	printf("PHILO numb must be betwen [1 <=> 200]\n");
	printf("Time to die, eat and sleep must be more than 60ms\n");
	printf("Valid example: ./philo 5 800 200 200\n");
	printf("----------------------------------------------------\n");
}

void	help_msg(void)
{
	printf("\033[32;1m\n+-----------------------------------------------+\n");
	printf("	PHILOSOPHERS HELP SHEET\n");
	printf("+-----------------------------------------------+\n\n\033[0m");
	help_params();
}

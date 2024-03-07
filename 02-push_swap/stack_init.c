#include "push_swap.h"
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>

//atol. str ---> lonlong value
static long ft_atoi(const char *s)
{
	long	num;
	int		neg;
	int		i;

	num = 0;
	neg = 1;
	i = 0;
	while (s[i] && ((s[i] >= 9 && s[i] <= 13)
								|| s[i] == ' '))
		i++;
	if (s[i] == '+')
		i++;
	else if (s[i] == '-')
	{
		neg = -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		num = (num * 10) + (s[i] - '0');
		i++;
	}
	return (num * neg);
}

/*
*	create the stack with command line values
*	checks are embedded in the creation itself
*			~Duplicate values
*			~Over | Underflow (desbordamiento, algo mas grande de lo que recibe)
*			~Syntax errors e
*
*		this flah is useful cause if its true. i have av in the HEAP to free
*/

void	stack_init(t_stack_node **a, char **av, bool flag_as_2)
{
	long	n;
	int		i;
	
	i = 0;
	while (av[i])
	{
		if (error_syntax(av[i]))
			error_free(a, av, flag_as_2);
		n = ft_atoi(av[i]);
		if (n > INT_MAX || n < INT_MIN)
			error_free(a, av, flag_as_2);
		if (error_repe(*a, (int)n))
			error_free(a, av, flag_as_2);
		append_node(a, (int)n);
		i++;
	} 
	if (flag_as_2)
		free_matrix(av);
}


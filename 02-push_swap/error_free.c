#include "push_swap.h"

void	free_matrix(char **av)
{
	int	i;

	i = -1;
	if (av == NULL || *av == NULL)
		return ;
	while (av[i])
		free(av[i++]);
	free(av - 1);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node *tmp;
	t_stack_node *currrent;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

/*
* Matrix starts from -1
* because i artificially made up
* equal to argv
*/

void	error_free(t_stack_node **a, char **av, bool flag_as_2)
{
	free_stack(a);
	if (flag_as_2)
		free_matrix(av);
	write(2, "Error\n", 6);
	exit(1);

}

int	error_syntax(char *str)
{
	if (!(*str == '+'
					|| *str == '-'
					|| (*str >= '0' && *str <= '9')))
		return (1);
	if ((*str == '+'
							|| *str == '-')
					&& !(str[1] >= '0' && str[1] <= '9')
		return (1);
	while (*++str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (1);
	}
	return (0);
}

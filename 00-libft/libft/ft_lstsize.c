#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int i;
	t_list *d;

	d = lst;
	i = 0;
	if (!lst)
		return (0);
	while(d)
	{
		d = d->next;
		i++;
	}
	return (i);
}

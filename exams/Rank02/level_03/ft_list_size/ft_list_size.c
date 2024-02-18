#include "ft_list.h"

//#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int	ft_list_size(t_list *begin_list)
{
	int i;

	i = 0;
	while (begin_list)
	{
		begin_list = begin_list->next;
		i++;
	}
	return (i);
}
/*
void	print_list(t_list *s)
{
	int i;

	i = 0;
	while(s)
	{
		printf("node %d----> %s\n", i, (char *)s->data);
		s = s->next;
		i++;
	}

}

t_list *ft_lstnew(void *content)
{
	t_list *new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (0);
	new->data = content;
	new->next = NULL;
	return (new);
}

int main(void)
{
	t_list *s;
	s = ft_lstnew("hola");
	s->next = ft_lstnew("buenas");
	s->next->next = ft_lstnew("tardes");
	print_list(s);
	printf("\ntotal lenght--> %d\n", ft_list_size(s));
	return (0);
}*/

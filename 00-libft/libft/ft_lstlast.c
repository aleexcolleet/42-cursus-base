#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list *d;

	if (!lst)
		return(lst);
	d = lst;
	printf("%s\n", (char *)d->content);
	while(d->next)
	{
		d = d->next;
	}
	return (d);
}
/*
int main(void)
{
	t_list *d;
	d = ft_lstnew("hola");
	d->next = ft_lstnew("buenas");
	d->next->next = ft_lstnew("familia");
	d->next->next->next = ft_lstnew("bien");
	ft_lstlast(d);
	printf("%s\t", (char *)d->content);
	free(d);
	return (0);
}*/

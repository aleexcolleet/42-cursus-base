#ifndef FT_LIST_H
# define FT_LIST_H

//libraries

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

//struct
typedef struct s_list
{
	struct s_list *next;
	void					*data;
}	t_list;

int	ft_list_size(t_list *begin_list);

#endif

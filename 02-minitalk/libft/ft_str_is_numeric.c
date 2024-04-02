#include "libft.h"

int	ft_str_is_numeric(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (0 == ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

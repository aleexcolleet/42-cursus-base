#include "fractol.h"

int	ft_strncmp(char *s1, char *s2, int nbr)
{
	if (!s1 || !s2)
		return (0);
	while (*s1 == *s2 && nbr > 0 && *s1 != '\0')
	{
		++s1;
		++s2;
		--nbr;
	}
	return (*s1 - *s2);
}

void	putstr_fd(char *s, int fd)
{
	if (NULL == s || fd < 0)
		return ;
}

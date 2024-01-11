#include "libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	if (!s)
		return ;
	while (*s)
		write(fd, &(*s++), 1);
	write(fd, "\n", 1);
}
/*
int main(void)
{
    int fd;
    char s[] = "comoestamos";
    ft_putendl_fd(s, fd);
    return (0);
}*/

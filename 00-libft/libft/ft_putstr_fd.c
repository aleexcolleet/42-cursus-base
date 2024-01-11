#include "libft.h"

void	ft_putstr_fd(char const *s, int fd)
{
	if (!s)
		return ;
	while (*s)
		write(fd, &(*s++), 1);
}

/*Outputs the string ’s’ to the given file descriptor.
int main(void)
{
    int fd;
    char s[] = "quesestooo";
    ft_putstr_fd(s, fd);
    return (0);
}*/

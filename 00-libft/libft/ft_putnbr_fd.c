#include "libft.h"

void ft_putnbr_fd(int n, int fd)
{
	char *str;
	char *fun = ft_itoa(n);

	str = fun;
	while (*str++)
		write(fd, str, 1);
}
/*
int main(void)
{
	int fd = open("example.txt", O_WRONLY | O_TRUNC, 0644);
	
	if (fd == -1)
	{
		exit(EXIT_FAILURE);
	}
	ft_putnbr_fd(2345, fd);
	close(fd);
	return (0);
}*/

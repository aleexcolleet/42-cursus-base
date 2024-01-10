#include "libft.h"

void ft_putendl_fd(char *c, int fd)
{
    size_t i;

    i = 0;
    while (i < ft_strlen(c))
    {
        ft_putchar_fd(c[i], fd);
        i++;
    }
    write(fd, '\n', 1);
}
/*
int main(void)
{
    int fd;
    char s[] = "comoestamos";
    ft_putendl_fd(s, fd);
    return (0);
}*/
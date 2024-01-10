#include "libft.h"

void ft_putstr_fd(char *c, int fd)
{
    size_t i;

    i = 0;
    while (i < ft_strlen(i))
    {
        ft_putchar_fd(c[i], fd);
        i++;
    }
}

/*
int main(void)
{
    int fd;
    char s[] = "quesestooo";
    ft_putstr_fd(s, fd);
    return (0);
}*/
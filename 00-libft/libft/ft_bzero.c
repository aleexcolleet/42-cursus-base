#include <stdio.h>
#include <stdlib.h>

void ft_bzero(void *str, size_t n)
{
    unsigned char *p;

    p = str;
    while (n)
    {
        *p = 0;
        p++;
        n--;
    }
}

int main()
{
    int n = 4;
    char str[] = "Helloooooo";
    ft_bzero(str, n);

    return 0;
}
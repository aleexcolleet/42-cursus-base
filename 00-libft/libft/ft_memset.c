#include <stdio.h>

void *ft_memset(void *ptr, int value, size_t num)
{
    size_t i;
    char *str;

    i = 0;
    str = (char *)ptr;

    while (num > i)
    {
        str[i] = value;
        i++;
    }
    return (ptr);
}

int main(void)
{
    char str[20];

    ft_memset(str, '6', 12);
    printf("%s", str);

    return (0);
}

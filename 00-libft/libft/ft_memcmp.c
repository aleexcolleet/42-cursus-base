#include <stdio.h>
#include <string.h>

int ft_memcmp(void *dest, const void *src, size_t n)
{
    unsigned char *d;
    unsigned char *s;

    d = (unsigned char *)dest;
    s = (unsigned char *)src;
    while (n && *d == *s)
    {
        ++d;
        ++s;
        --n;
    }
    if (n)
        return (*d - *s);
    else
        return (0);
}
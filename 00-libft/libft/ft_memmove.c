#include <stdio.h>

void *ft_memmove(void *dest, const void *src, size_t n)
{
    unsigned char *d;
    const unsigned char *s;

    d = (unsigned char *)dest;
    s = (unsigned char *)src;

    if (!(src && dest))
        return (dest);
    if (dest < src)
        return (ft_memcpy(dest, src, n));
    while (n--)
        d[n] = s[n];
    return (dest);
}

int main(void)
{
    char str[] = "lamadredelbravo.";
    char dest[1];
    printf((ft_memmove(dest, str, 10)));
}
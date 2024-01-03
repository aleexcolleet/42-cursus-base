#include <stdio.h>

void *ft_memcpy(void *dest, const void *src, size_t n)
{
    unsigned char *d;
    unsigned char *s;

    d = (unsigned char *)dest;
    s = (unsigned char *)src;

    if (!dest && !src)
        return (dest);

    while (n > 0)
    {
        *d = *s;
        s++;
        d++;
        n--;
    }
    return (dest);
}

int main(void)
{
    char dest[] = "ooooooo";
    char src[] = "aaaaaaa";

    printf("elmio----> %s", ft_memcpy(dest, src, 5));

    return (0);
}
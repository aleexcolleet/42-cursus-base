#include <stdio.h>

size_t strlcpy(char *dest, const char *src, size_t size) // size of dest
{
    size_t i;

    i = 0;
    // primero lo protegemos
    if (!size)
        return (ft_strlen(src));

    // Copiar string a dest
    while (i < (size - 1) && src[i])
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (ft_strlen(src));
}

int main(void)
{
    char dest[0];
    char src[] = "comoestatuhermana";
    printf("original %s\n", src);
    printf("tiene %d bytes\n", strlcpy(dest, src, sizeof(dest)));
    printf("dest es: %s\n", dest);
    return (0);
}
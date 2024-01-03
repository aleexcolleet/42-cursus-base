#include <stdio.h>
#include <string.h>

size_t ft_strlen(const char *str)
{
    size_t i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

int main(void)
{
    const char hola[] = "holabuenas";
    int result = ft_strlen(hola);
    printf("el string tiene %d bytes\n", result);
    printf("el string realmente tiene %d\n", strlen(hola));
    return (0);
}
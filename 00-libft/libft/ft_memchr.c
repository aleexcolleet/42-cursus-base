#include <stdio.h>

void *ft_memchr(const void *s, int c, size_t n)
{
    size_t i;

    i = 0;
    while (i < n)
    {
        if (((unsigned char *)s)[i] == (unsigned char)c)
            return ((void *)s + i);
        i++;
    }
    return (0);
}
int main()
{
    unsigned char buffer[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int target_value = 5;
    size_t buffer_size = sizeof(buffer);

    printf("Numeros del array:\n");
    for (size_t i = 0; i < 9; i++)
    {
        printf("%d", buffer[i]);
        if (i < 8)
            printf(", ");
    }
    printf("\nNumero a buscar dentro del array: %d\n", target_value);
    void *result = ft_memchr(buffer, target_value, buffer_size);

    if (result)
        printf("El valor %d fue encontrado.\n", target_value);
    else
        printf("El valor %d no fue encontrado.\n", target_value);
    return 0;
}
#include <stdlib.h>

void *ft_calloc(size_t num, size_t size)
{
    int i;
    size_t total;
    unsigned char *array;
    void *p;

    total = num * size;
    p = (void *)malloc(total);
    if (p != NULL)
        array = (unsigned char *)p;
    i = 0;
    while (i < total)
        array[i++] = 0;
    return p;
}
int main(void)
{
    int *result = ft_calloc(5, 4);
    free(result);

    return (0);
}
#include "philo.h"
void    *ft_memset(void *b, int c, size_t len)
{
    size_t    i;

    i = 0;
    while (i < len)
    {
        ((unsigned char *)b)[i] = (unsigned char)c;
        i++;
    }
    return (b);
}

void    ft_bzero(void *s, size_t n)
{
    ft_memset(s, 0, n);
}

void    *ft_calloc(size_t count, size_t size)
{
    void    *bzero;

    bzero = (void *)malloc(count * size);
    if (!bzero)
        return (0);
    ft_bzero (bzero, count * size);
    return (bzero);
}

/*
void *ft_calloc(size_t num_elements, size_t element_size)
{
	void *ptr;

	ptr = malloc(num_elements * element_size);
	if (!ptr)
		return (NULL);
	memset(ptr, 0, num_elements * element_size);
	return ptr;
}*/

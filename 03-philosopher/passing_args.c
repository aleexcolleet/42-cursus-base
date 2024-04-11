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

long ft_atol(const char *str, t_data *p)
{
    int		i;
    long    resultado;
	int		len;

	len = 0;
    i = 0;
    resultado = 0;
    if ((str[i] == ' ') || (str[i] >= 9 && str[i] <= 13))
    {
        return (-1);
    }
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            return (-1);
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        resultado = resultado * 10 + str[i] - '0';
        i++;
		len++;
    }
    if (str[i] != '\0')
        return (-1);
	if (resultado > INT_MAX || len > 10)
		p->error = -1;
    return (resultado);
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

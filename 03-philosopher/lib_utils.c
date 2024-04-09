#include "philo.h"

void *ft_calloc(size_t num_elements, size_t element_size)
{
	void *ptr;

	ptr = malloc(num_elements * element_size);
	if (!ptr)
		return (NULL);
	memset(ptr, 0, num_elements * element_size);
	return ptr;
}

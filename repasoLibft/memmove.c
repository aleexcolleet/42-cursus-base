//#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *ft_memmove(void *dst, const void *src, size_t len)
{
	size_t i;

	if (!dst || !src)
		return (NULL);
	if (dst > src)
	{
		i = len;
		while (i-- > 0)
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
	}
	else
	{
		i = 0;
		while (i < len)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dst);
}

int main(void)
{
	char str1[18];
	char str2[20];
	strcpy(str1, "holabuenas aaaae");
	puts(str1);
	ft_memmove(str2, str1, 10);
	puts(str2);
	return (0);
}

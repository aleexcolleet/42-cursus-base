#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

size_t ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (dst[i] && src[i] && (size + 1) > (i + j))
	{
		while (dst[i])
		{
			i++;
		}
		while (src[j])
		{
			dst[i + j] = src[j];
			j++;
		}
	}
	dst[i + j] = '\0';
	return (i + j);
}
int main(void)
{
	char dst[20] = "hola";
	char *src = "buenas";
	printf("length---> %zu\n", ft_strlcat(dst, src, 10));
	printf("resultado-> %s\n", dst);
	return (0);
}

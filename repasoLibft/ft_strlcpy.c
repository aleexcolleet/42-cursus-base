#include <stdio.h>

size_t	ft_strlcpy(char *dst, const char *str, size_t size)
{
	if(!str)
	{
		return (0);
	}
	size_t i;

	i = 0;
	while (str[i] && (size - 1) > i)
	{
		dst[i] = str[i];
		i++;
	}
	if (i != 0)
		dst[i] = '\0';
	return (i);
}
int main(void)
{
	char dst[30];
	const char *src = "holabuenas";
	printf("lenght--> %zu\n", ft_strlcpy(dst, src, 5));
	printf("result--> %s\n", dst);
	return (0);

}

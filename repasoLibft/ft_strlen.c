#include <stdio.h>

size_t	ft_strlen(char *s)
{
	size_t i;

	i = 0;
	while(s[i])
	{
		i++;
	}
	return (i);

}
int main(void)
{
	char *s = "hola";
	int resultado = ft_strlen(s);
	printf("lenght---> %d", resultado);
	return (0);
}

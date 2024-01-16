#include <stdio.h>
#include <stdlib.h>

void *ft_memset(void *b, int c, size_t len)
{
	unsigned char *pb;
		
	pb = (unsigned char *)b;
	while (len)
	{
		*pb++ = (unsigned char)c;
		len--;
	}
	return (pb);
}
int main(void)
{
	char str[20];
	ft_memset(str, 'a', 5);
	printf("elmio---> %s\n", str);
	//memset(str, 'a', 5);
	//printf("original--> %s\n", (char *)str);

	return (0);
}

#include "ft_printf.h"
#include "libft.h"

//just for test purposes
#include <stdio.h>
int	main(void)
{
	char *string = "Hello, World!";
	int integer = -12381;
	char character = 'A';
	void *ptr = (void *)&integer;
//	unsigned int hexadecimal = 0x1A3F;
//	usnigned int HEXADECIMAL = 0x1A3F;

	//~~probandoo~~//
	
	//--char--//
		ft_printf("\n<----------------------------->\n\n");
	ft_printf("Flag 'c' ~ char\n\n");
	ft_printf("fake: %c\n", character);
	printf("real: %c\n", character);
		ft_printf("\n<------------------------------>\n\n");
	
	//--string--//
	ft_printf("flag 's' ~ string\n\n");
	ft_printf("fake: %s\n", string);
	printf("real: %s\n", string);
		ft_printf("\n------------------------------>\n\n");

	//--pointer--//
	ft_printf("Flag 'p' ~pointerDirection\n\n");
	ft_printf("Fake: %p\n", ptr);
	printf("Real: %p\n", ptr);
		ft_printf("\n------------------------------>\n\n");

	//--decimal(base10)--//
	ft_printf("Flag 'd' ~entero(base10)\n\n");
	ft_printf("Fake: %d\n", integer);
	printf("Real: %d\n", integer);
		ft_printf("\n------------------------------>\n\n");
	return (0);
}

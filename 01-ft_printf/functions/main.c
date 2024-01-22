#include "ft_printf.h"
#include "libft.h"

//just for test purposes
#include <stdio.h>
int	main(void)
{
	char *string = "Hello, World!";
//	int integer = 5;
	char character = 'A';
//	void *ptr = (void *)&integer;
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
	int	i = ft_printf("%s", string);
	printf("lenght---> %d", i);
	
	ft_printf("\n------------------------------>\n\n");
	return (0);
}

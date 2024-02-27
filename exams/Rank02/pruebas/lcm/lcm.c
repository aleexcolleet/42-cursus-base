#include <stdio.h>

unsigned int	lcm(unsigned int a, unsigned int b)
{
	unsigned int lcm;

	if (!a || !b)
		return (0);
	if (a > b)
		lcm = a;
	else
		lcm = b;
	while ("lcm")
	{
		if (((lcm % a) == 0) && ((lcm % b) == 0))
			return (lcm);
		lcm++;
	}
}

int main()
{
	printf("%u\n", lcm(14, 24));
}

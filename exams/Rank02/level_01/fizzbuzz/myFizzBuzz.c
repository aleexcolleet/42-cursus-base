#include <unistd.h>

int main(void)
{
	int i = 0;

	while (i < 100)
	{
		if ((i % 3) == 0 || (i % 5) == 0)
		{
			if ((i % 3) == 0)
				write(1, "fizz", 3);
			else if ((i % 5) == 0)
				write(1, "buzz", 3)
			i++;
			write(1, '\n', 1);
		}
		write(1, &(char)i, 1);
	}
	return (0);
}

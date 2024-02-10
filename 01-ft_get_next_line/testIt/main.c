#include "get_next_line.h"

int	main(void)
{
	int fd;
	int i = 0;

	fd = open("test.txt", O_RDONLY);

	while (i < 2)
	{
		printf("next line---> %s\n", get_next_line(fd));
		i++;
	}
	close(fd);
	
}

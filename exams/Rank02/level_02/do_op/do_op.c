#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

void	do_op(char *op1, char op, char *op2)
{
	int	first;
	int	second;
	int	result;

	result = 0;
	first = atoi(op1); //los tengo en int
	second = atoi(op2);
	if (op == '+')
		result = first + second;
	else if (op == '-')
		result = first - second;
	else if (op == '*')
			result = first * second;
	else if (op == '/')
		result = first / second;
	printf("%d", result);
}

int main(int args, char **argv)
{
	if (args == 4)
	{
		if(argv[2][1] == '\0')
			do_op(argv[1], argv[2][0], argv[3]); //entiendo que si mandas mas de un operador(/ * + -)
	}
	printf("\n");
	return (0);
}

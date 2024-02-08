int	ft_atoi(const char *str)
{
	int i;
	int sign;
	int res;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == ' ' || str[i] >= 9 && str[i] <= 13)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		res *= 10;
		res += str[i] - '0';
		i++;
	}
	return (res * sign);
}
/*
int main(int args, char **argv)
{
	if (args == 2)
	{
		printf("res--> %d\n\n", ft_atoi(argv[1]));
		printf("reeees---> %d\n", atoi(argv[1]));
	}
	else
		printf("error\n");
	return (0);
}*/

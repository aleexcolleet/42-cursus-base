# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

static void	action(int sig)
{
	static int	received = 0;

	if (sig == SIGUSR1)
		++received;
	else
	{
		ft_putnbr_fd(received, 1);
		ft_putchar_fd('\n', 1);
		exit(0);
	}
}

static void	mt_kill(int pid, char *str)
{
	int		i;
	char	c;
	while (*str)
	{
		i = 8;
		c = *str++;
		while(i--)
		{
			if (c >> i & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(100);
		}
	}
	i = 8;
	while (i--)
	{
		kill(pid, SIGUSR1);
		usleep(100);
	}
}

int	main(int as, char **av)
{
	if ((ft_strlen(av[1]) > 11 && !ft_str_is_numeric(av[1])) || as != 3)
		return (1);
	else if (!ft_strlen(av[2]))
		return (1);
	ft_putstr_fd("Sent            :", 1);
	ft_putnbr_fd(ft_strlen(av[2]), 1);
	ft_putstr_fd("\tReceived: ", 1);
	signal(SIGUSR1, action);
	signal(SIGUSR2, action);
	mt_kill(ft_atoi(av[1]), av[2]);
	while ("infinite loop")
		pause();
	return (0);

}

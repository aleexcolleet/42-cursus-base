# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"



int	main(int as, char **av)
{
	if ((ft_strlen(av[1]) > 11 && !ft_str_is_numeric(argv[1])) || as != 3)
		return (1);
	else if (!ft_strlen(av[2]))
		return (1);
	ft_putstr_fd("Sent            :", 1);
	ft_putnbr_fd(ft_strlen(av[2]), 1);
	ft_putstr_fd("\tReceived: \n", 1);
	signal(SIGUSR1, action);
	signal(SIGUSR2, action);
	mt_kill(ft_atoi(av[1]), av[2]);
	while ("infinite loop")
		pause();
	return (0);

}

#ifndef CHECKER_H
# define CHECKER_H

# define BUFFER_SIZE 15
# include <fcntl.h>
# include "../push_swap/push_swap.h"

void	ft_bzero(void *s, size_t n);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);

char	*get_next_line(int fd);
static void	get_result(char **stash, char **result);
static void	remove_result(char **stash);
static int	read_buffer(int fd, char **stash, char *buffer);



#endif

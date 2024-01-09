#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "libft.h"

void ft_putchar_fd(char c, int fd)
{
    // open file
    fd = open("myExample.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (fd = -1)
    {
        perror("Error opening myExample");
        exit(EXIT_FAILURE);
    }

    // write into the file
    const char *message;
    ssize_t bytes_written;

    message = "Hello, File descriptor!'n";
    bytes_written = write(fd, message, strlen(message))
}

int main(void)
{
    int fd;

    return (0);
}
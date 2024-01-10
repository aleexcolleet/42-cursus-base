#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
// #include "libft.h"
size_t ft_strlen(const char *str)
{
    size_t i;

    i = 0;
    while (str[i] != '\0')
        i++;
    return (i);
}

void ft_putstr_fd(char c, int fd)
{
    // open file
    fd = open("firstFileDescriptor.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (fd == -1)
    {
        perror("Error opening myExample");
        exit(EXIT_FAILURE);
    }

    // write into the file
    const char *message;
    ssize_t bytes_written;

    message = &c;
    bytes_written = write(fd, message, strlen(message));

    if (bytes_written == -1)
    {
        perror("Error writing to file");
        close(fd);
        exit(EXIT_FAILURE);
    }
    printf("Successfully wrote %zd bytes", bytes_written);
    close(fd);
}

int main(void)
{
    int fd;
    ft_putstr_fd('v', fd);
    return (0);
}
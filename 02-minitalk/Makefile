SOURCES = server.c client.c
OBJECTS = $(SOURCES:.c=.o)

cc = gcc
CFLAGS = -Wall -Wextra -Werror

all: server client

server: server.o libft
	$(CC) -o $@ $< -Llibft -lft

client: client.o libft
	$(CC) -o $@ $< -Llibft -lft

%.o: %.client
	$(CC) -c $(CFLAGS) $?

libft:
	make -C libft

clean:
	rm -f $(OBJECTS)
	make -C libft clean

fclean:	clean
	rm -f server client libft/libft.a

re: fclean all

.PHONY: all bonus libft clean fclean re

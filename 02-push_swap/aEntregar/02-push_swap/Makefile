# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acollet- <acollet-@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/07 12:47:13 by acollet-          #+#    #+#              #
#    Updated: 2024/03/07 12:47:16 by acollet-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
ARCHIVE = push_swap.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g -O2 
MAKE_LIB = ar -rcs

SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(ARCHIVE)
	$(CC) $< -o $@

$(ARCHIVE) : $(OBJS)
	$(MAKE_LIB) $(ARCHIVE) $^

%.o : %.c 
	$(CC) $(CFLAGS) -c $< -o $@ 

bonus : 
	cd ../checker && make
	
clean :
	rm -f $(OBJS) $(ARCHIVE)

fclean : clean
	rm -f $(NAME)
	cd ../checker && make fclean

re : fclean all

.PHONY : all clean fclea re

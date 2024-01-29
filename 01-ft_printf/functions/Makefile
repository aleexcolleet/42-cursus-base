# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acollet- <acollet-@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/29 11:18:01 by acollet-          #+#    #+#              #
#    Updated: 2024/01/29 11:18:52 by acollet-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCS = ft_putchar.c \
       ft_printf.c \
       ft_puthexa.c \
       ft_putnbr.c \
       ft_putstr.c \
       ft_unsfunct.c \
       print_adress.c \
       validate_format.c

FLAGS = -Wall -Wextra -Werror -MMD
OBJS = $(SRCS:.c=.o)
LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a
DEPS = $(SRCS:.c=.d)

CC = gcc

all: $(NAME)

%.o:%.c Makefile ft_printf.h $(LIBFT_PATH)/libft.h
	$(CC) $(FLAGS) -I . -I $(LIBFT_PATH) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT)
	ar rcs $(NAME) $(OBJS)

$(LIBFT):
	@make -C $(LIBFT_PATH)

clean:
	rm -f $(OBJS) $(DEPS)
	make -C $(LIBFT_PATH) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_PATH) fclean

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re

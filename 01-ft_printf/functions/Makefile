# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acollet- <acollet-@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/25 12:31:31 by acollet-          #+#    #+#              #
#    Updated: 2024/01/27 11:36:48 by acollet-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RESET = \033[0m
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
MAGENTA = \033[35m
CYAN = \033[36m
WHITE = \033[37m
BOLD = \033[1m

NAME = libftprintf.a 
SRCS = ft_putchar.c \
       ft_printf.c \
       ft_puthexa.c \
       ft_putnbr.c \
       ft_putstr.c \
	   ft_unsfunct.c \
	   print_adress.c \
	   validate_format.c \
       main.c 

FLAGS = -Wall -Wextra -Werror -MMD
OBJS = $(SRCS:.c=.o)
LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a
DEPS = $(SRCS:.c=.d)
SILENCE = --no-print-directory

all: $(NAME)
CC = gcc

%.o:%.c Makefile ft_printf.h  libft libft/libft.h
	@echo "$(YELLOW)Compilando$(RESET) $(CYAN)$(BOLD) $<$(RESET)"
	@$(CC) $(FLAGS) -I ./ -c $< -o $@

$(NAME): $(OBJS) Makefile libft/Makefile
	@echo "$(BLUE)$(BOLD)$(NAME) ░░░░░░░░▄▄▄██████▀▀██████▄▄▄░░░░░░░░"
	@echo "$(BLUE)$(BOLD)$(NAME) ░░░░▄███▀█▄░░░░░▄░░▄░░░░░▄█▀███▄░░░░"
	@echo "$(BLUE)$(BOLD)$(NAME) ░░██▀█▄████░░░░░████░░░░░████▄█▀██░░"
	@echo "$(BLUE)$(BOLD)$(NAME) ▄█▀▄███████▄▄░▄▄████▄▄░▄▄███████▄▀█▄"
	@echo "$(BLUE)$(BOLD)$(NAME) ██░██████████████████████████████░██"
	@echo "$(BLUE)$(BOLD)$(NAME) ▀██▀████▀░▀▀█▀░▀▀██▀▀░▀█▀▀░▀████▀██▀"
	@echo "$(BLUE)$(BOLD)$(NAME) ░░██▄█▀█▄░░░░░░░░▀▀░░░░░░░░▄█▀█▄██░░"
	@echo "$(BLUE)$(BOLD)$(NAME) ░░░░▀███▄▄▄░░░░░░░░░░░░░░▄▄▄███▀░░░░"
	@echo "$(BLUE)$(BOLD)$(NAME) ░░░░░░░░▀▀▀████COLLETE████▀▀▀░░░░░░░░"
	@echo "$(BLUE)$(BOLD)$(NAME) "$(RESET)
	@echo "$(WHITE)$(BOLD)$(NAME)y...$(RESET)"
	@make -C $(LIBFT_PATH) all $(SILENCE)
	@ar rcs $(NAME) $(OBJS)
	@echo "$(YELLOW)$(BOLD)$(NAME) COMPILADO$(RESET)"
	@echo "$(GREEN)$(BOLD)HECHO !$(RESET)"

clean:
	@echo "Remove .o  ..."
	@rm -f $(OBJS) $(DEPS)
	@make -C $(LIBFT_PATH) clean $(SILENCE)
	@echo "$(GREEN)$(BOLD)HECHO !$(RESET)"

fclean: clean
	@echo "Remove ..."
	@rm -f $(NAME)
	@make -C $(LIBFT_PATH) fclean $(SILENCE)
	@echo "$(GREEN)$(BOLD)HECHO !$(RESET)"

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re libft 

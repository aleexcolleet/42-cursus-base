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

# Definición de colores
GREEN = \033[0;32m
RED = \033[0;31m
NC = \033[0m # No colores
BLUE = \033[34m

NAME = push_swap
ARCHIVE = push_swap.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g -O2 
MAKE_LIB = ar -rcs

SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

all : $(NAME)
	@echo "$(GREEN)Completed_Compilation$(NC)"

$(NAME) : $(ARCHIVE)
	@echo "$(GREEN)Compiling $@...$(NC)"
	@$(CC) $< -o $@

$(ARCHIVE) : $(OBJS)
	@$(MAKE_LIB) $(ARCHIVE) $^

%.o : %.c Makefile
	@$(CC) $(CFLAGS) -c $< -o $@ 

bonus : 
	@cd ../checker && make
	
clean :
	@echo "$(RED) Cleaning...$(NC)"
	@rm -f $(OBJS) $(ARCHIVE)

fclean : clean
	@echo "$(RED) More_Cleaning...$(NC)"
	@rm -f $(NAME)
	@cd ../checker && rm -f checker

re : fclean all

.PHONY : all clean fclea re

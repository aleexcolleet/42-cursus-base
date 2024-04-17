#FANCY
RESET = \033[0m
RED = \033[31m
#GREEN COLORS
GREEN = \033[32m
BRIGHT_GREEN = \033[92m
BOLD_GREEN = \033[32;1m
#####
YELLOW = \033[33m
BLUE = \033[34m
MAGENTA = \033[35m
CYAN = \033[36m
WHITE = \033[37m
BOLD = \033[1m
SILENCE = --no-print-directory

#PROG NAME
NAME = philo
LIBRARY = philo.a
# COMPILER
CC		= gcc
FLAGS	= -Werror -Wextra -Wall -MMD -g
MAKE_LIB = ar -rcs

#includes
INCLUDES	= philo.h

#sources
SRCS			=	philo.c \
				init.c \
				passing_args.c \
				philo_utils.c \
				help_msg.c \

#Objects
OBJS		= $(SRCS:.c=.o)
DEPS		= $(SRCS:.c=.d)
SILENCE = --no-print-directory

all: $(NAME)

$(NAME) : $(OBJS) $(DEPS) $(LIBRARY) philo.h Makefile
	@echo "$(CYAN) 🚀 COMPILING : 🤔$(RESET)"
	@echo "$(CYAN)"
	@echo "    ____  __  ________    ____  _____ ____  ____  __  ____________  _____"
	@echo "   / __ \/ / / /  _/ /   / __ \/ ___// __ \/ __ \/ / / / ____/ __ \/ ___/"
	@echo "  / /_/ / /_/ // // /   / / / /\__ \/ / / / /_/ / /_/ / __/ / /_/ /\__ \ "
	@echo " / ____/ __  // // /___/ /_/ /___/ / /_/ / ____/ __  / /___/ _, _/___/ / "
	@echo "/_/   /_/ /_/___/_____/\____//____/\____/_/   /_/ /_/_____/_/ |_|/____/  "
	@echo "$(RESET)"
	@$(CC) -o $(NAME) $(LIBRARY)
	@echo "$(BOLD_GREEN) PHILO COMPILED SUCCESFULLY 😎$(RESET)"

$(LIBRARY) : $(OBJS)
	@$ $(MAKE_LIB) $(LIBRARY) $^

%.o : %.c
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@echo "$(BOLD_GREEN) CLEANING FILES... $(RESET)"
	@rm -f $(OBJS) $(DEPS) philo.a
	@echo "$(BOLD_GREEN) DONE  $(RESET)"

fclean: clean
	@echo "$(YELLOW) CLEANING PROGRAM ... $(RESET)"
	@rm -f $(NAME) $(DEPS) philo.a
	@echo "$(BOLD_GREEN) DONE  $(RESET)"

re: fclean all

.PHONY: all clean fclean re

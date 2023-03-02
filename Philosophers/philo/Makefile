NAME = philo

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = philo.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "\033[1;32m Philo is ready!\033[0m"

.c.o:
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
	@echo "\033[1;32m $< Compiled!\033[0m"

clean:
	@rm -f $(OBJS)
	@echo "\033[1;31m Cleaned Seccessfully!\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[1;31m Full cleaned Seccessfully!\033[0m"

re: fclean all

.PHONY: all clean fclean re
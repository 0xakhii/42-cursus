NAME = push_swap

LIBFT = -L libft -lft

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRCS = push_swap.c utils.c utils2.c utils3.c op.c\
	op2.c op3.c sort.c\

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Compiling libft..."
	@make -C libft
	@echo "\033[1;32mLIbft compiled ✅\033[0m"
	@$(CC) $(LIBFT) $(OBJS) -o $(NAME)
	@echo "Compiling push_swap..."
	@echo "\033[1;32mpush_swap compiled ✅\033[0m"

.c.o :
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
	@echo "\033[1;32m$< compiled ✅\033[0m"

clean:
	@echo "\033[1;31mPerforming a cleaning...\033[0m"
	@make clean -C libft
	@$(RM) $(OBJS)
	@sleep 0.5;
	@echo "\033[1;32mCleaning done ✅\033[0m"

fclean: clean
	@echo "\033[1;31mPerforming a full cleaning...\033[0m"
	@make fclean -C libft
	@$(RM) $(NAME)
	@sleep 0.5;
	@echo "\033[1;32mFull cleaning done ✅\033[0m"

re: fclean all

.PHONY: all clean fclean re

test: all clean
	clear;
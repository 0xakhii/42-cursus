NAME = push_swap

NAME_BONUS = checker

LIBFT = -L libft -lft

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRCS = push_swap.c utils.c utils2.c utils3.c op.c\
	op2.c op3.c sort.c\

SRCS_BONUS = bonus/checker.c bonus/utils_bonus.c bonus/utils2_bonus.c bonus/utils3_bonus.c bonus/op_bonus.c\
	bonus/op2_bonus.c bonus/op3_bonus.c bonus/get_next_line.c bonus/get_next_line_utils.c bonus/sort_bonus.c\

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME): $(OBJS)
	@echo "Compiling libft..."
	@make -C libft
	@echo "\033[1;32mLibft compiled ✅\033[0m"
	@$(CC) $(LIBFT) $(OBJS) -o $(NAME)
	@echo "Compiling push_swap..."
	@echo "\033[1;32mpush_swap compiled ✅\033[0m"

$(NAME_BONUS): $(OBJS_BONUS)
	@echo "Compiling libft..."
	@make -C libft
	@echo "\033[1;32mLibft compiled ✅\033[0m"
	@$(CC) $(LIBFT) $(OBJS_BONUS) -o $(NAME_BONUS)
	@echo "Compiling checker..."
	@echo "\033[1;32mchecker compiled ✅\033[0m"

.c.o :
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
	@echo "\033[1;32m$< compiled ✅\033[0m"

clean:
	@echo "\033[1;31mPerforming a cleaning...\033[0m"
	@make clean -C libft
	@$(RM) $(OBJS)
	@$(RM) $(OBJS_BONUS)
	@sleep 0.5;
	@echo "\033[1;32mCleaning done ✅\033[0m"

fclean: clean
	@echo "\033[1;31mPerforming a full cleaning...\033[0m"
	@make fclean -C libft
	@$(RM) $(NAME)
	@$(RM) $(NAME_BONUS)
	@sleep 0.5;
	@echo "\033[1;32mFull cleaning done ✅\033[0m"

re: fclean all

.PHONY: all clean fclean re

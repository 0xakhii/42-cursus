NAME = minishell

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

LIBS = -lreadline -L libft -lft

SRCS = main.c utils.c syntax_check.c expander.c lexer.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@make -C libft
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)
	@echo "\033[1;32mminishell is ready"

.c.o:
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean:
	@make -C libft clean
	@rm -f $(OBJS)
	@echo "\033[1;31mminishell objects are deleted"

fclean: clean
	@make -C libft fclean
	@rm -f $(NAME)
	@echo "\033[1;31mminishell is deleted"

re: fclean all

.PHONY: all clean fclean re

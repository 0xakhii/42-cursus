NAME = push_swap

LIBFT = -L libft -lft

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRCS = push_swap.c utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft
	$(CC) $(LIBFT) $(OBJS) -o $(NAME)

clean:
	make clean -C libft
	$(RM) $(OBJS)

fclean: clean
	make fclean -C libft
	$(RM) $(NAME)

re: fclean all
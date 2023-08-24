CC          = cc

NAME        = cub3D

LIBFT_NAME  = libft.a

SRCS        =   get_next_line/get_next_line.c get_next_line/get_next_line_utils.c main.c parse.c\
	utils.c map_check.c

OBJS        = $(SRCS:.c=.o)

CFLAGS      = -Wall -Wextra -Werror -g3 -fsanitize=address

LINUX_LIBS      = -L libft -lft  -lmlx -L/usr/lib -lXext -lX11 -lm -lz

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft
	$(CC) $(CFLAGS) $(OBJS) $(LINUX_LIBS) -o $(NAME)

clean:
	rm -rf $(OBJS)
	make -C libft clean

fclean: clean
	rm -rf $(NAME)
	make -C libft fclean

re: fclean all

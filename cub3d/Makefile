CC          = cc

NAME        = cub3D

LIBFT_NAME  = libft.a

SRCS        =   get_next_line/get_next_line.c get_next_line/get_next_line_utils.c main.c parse.c\
	utils.c map_check.c

OBJ        = $(SRCS:.c=.o)

CFLAGS      = -Wall -Wextra -Werror -g3 -fsanitize=address

LINUX_FLAGS = -L libft -lft -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

all: $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@


$(NAME): $(OBJ)
	@make -C libft
	$(CC) $(OBJ) $(LINUX_FLAGS) -o $(NAME)

clean:
	rm -rf $(OBJ)
	make -C libft clean

fclean: clean
	rm -rf $(NAME)
	make -C libft fclean

re: fclean all

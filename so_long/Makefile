NAME = so_long

LIBFT = libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRCS = map.c so_long_utils.c get_next_line.c get_next_line_utils.c \
	so_long.c path.c window.c utils.c p_move.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(LIBFT) :
	make -C libft

$(NAME) : $(LIBFT) $(OBJS)
	$(CC) $(OBJS) -L libft -lft -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean :
	make clean -C libft
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

test : all clean 
	clear && ./so_long maps/map1.ber
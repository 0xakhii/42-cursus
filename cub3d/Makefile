NAME = cub3d

LIBFT = libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRCS = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c main.c parse.c\
	utils.c

OBJS = $(SRCS:.c=.o)


all : $(NAME)

$(LIBFT) :
	make -C libft

$(NAME) : $(LIBFT) $(OBJS)
	@$(CC) $(OBJS) -L libft -lft -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean :
	make clean -C libft
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean : clean
	make fclean -C libft
	$(RM) $(NAME) $(NAME_BONUS)

re : fclean all

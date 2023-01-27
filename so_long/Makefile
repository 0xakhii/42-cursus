NAME = so_long

NAME_BONUS = so_long_bonus

LIBFT = libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRCS = map.c so_long_utils.c get_next_line.c get_next_line_utils.c \
	so_long.c path.c window.c utils.c p_move.c re_render.c

SRCS_BONUS = bonus/map_bonus.c bonus/so_long_utils_bonus.c bonus/get_next_line_bonus.c \
	bonus/get_next_line_utils_bonus.c bonus/so_long_bonus.c bonus/path_bonus.c \
	bonus/window_bonus.c bonus/utils_bonus.c bonus/p_move_bonus.c bonus/re_render_bonus.c

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all : $(NAME)

$(LIBFT) :
	make -C libft

$(NAME) : $(LIBFT) $(OBJS)
	$(CC) $(OBJS) -L libft -lft -lmlx -framework OpenGL -framework AppKit -o $(NAME)

bonus : $(NAME_BONUS)

$(NAME_BONUS) : $(LIBFT) $(OBJS_BONUS)
	$(CC) $(OBJS_BONUS) -L libft -lft -lmlx -framework OpenGL -framework AppKit -o $(NAME_BONUS)

clean :
	make clean -C libft
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean : clean
	$(RM) $(NAME) $(NAME_BONUS)

re : fclean all

test : all clean 
	clear && ./so_long maps/map1.ber

test_bonus : bonus clean
	clear && ./so_long_bonus maps/map1.ber
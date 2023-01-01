NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror 

RM = rm -f

SRCS = map.c so_long_utils.c get_next_line.c get_next_line_utils.c so_long.c 

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean : 
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

test : all clean 
	clear && ./so_long maps/map.ber
NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror 

RM = rm -f

SRCS = main.c 

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean : $(RM) $(OBJS)

fclean : clean
	so_long

re : fclean all

test : all clean
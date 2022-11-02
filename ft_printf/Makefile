NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SOURCES = ft_printf.c \
		

OBJECTS = $(SOURCES:.c=.o)

all : $(NAME)

$(NAME) : $(OBJECTS)
		$(CC) -o printf $(OBJECTS)
		ar rc $(NAME) $(OBJECTS)

clean : rm -f $(OBJECTS)

fclean : clean
		$(NAME)

re : fclean all

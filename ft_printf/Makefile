NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SOURCES = ft_printf.c ft_putchar.c ft_putnbr.c \
		ft_putstr.c ft_putunsigned.c ft_puthex_upper.c \
		ft_puthex_lower.c ft_putptr.c 


OBJECTS = $(SOURCES:.c=.o)

all : $(NAME)

$(NAME) : $(OBJECTS)
		$(CC) -o printf $(OBJECTS)
		ar rc $(NAME) $(OBJECTS)

clean : rm -f $(OBJECTS)

fclean : clean
		$(NAME)

re : fclean all

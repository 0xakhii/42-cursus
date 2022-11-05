NAME = libftprintf.a

CC = cc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

SOURCES = ft_printf.c ft_putchar.c ft_putnbr.c \
		ft_putstr.c ft_putunsigned.c ft_puthex_upper.c \
		ft_puthex_lower.c ft_putptr.c 


OBJECTS = $(SOURCES:.c=.o)

all : $(NAME)

$(NAME) : $(OBJECTS)
		ar rc $(NAME) $(OBJECTS)

clean :	
		$(RM) $(OBJECTS)

fclean : clean
		$(RM) $(NAME)

re : fclean all

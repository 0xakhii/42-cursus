NAME = libft.a

CC = cc

CFLAGS += -Werror -Wextra -Wall

  SOURCES = ft_memcpy.c ft_bzero.c ft_memset.c \
	 ft_isalnum.c ft_isdigit.c ft_isalpha.c \
	 ft_isascii.c ft_strlcat.c ft_strlcpy.c \
	 ft_toupper.c ft_tolower.c ft_strlen.c \
	 ft_isprint.c ft_strnstr.c ft_strncmp.c \
	 ft_atoi.c ft_memchr.c ft_memcmp.c \
	 ft_memmove.c ft_calloc.c ft_strchr.c \
	 ft_strdup.c ft_strrchr.c ft_strtrim.c \
	 ft_substr.c ft_putchar_fd.c ft_putstr_fd.c \
	 ft_putendl_fd.c ft_putnbr_fd.c ft_strjoin.c \
	 ft_strmapi.c ft_striteri.c ft_itoa.c \
	 ft_split.c ft_lstsize.c ft_lstadd_back.c \
	 ft_lstlast.c ft_lstadd_front.c ft_lstnew.c \
	 ft_strcmp.c \

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)
	@:
$(NAME): $(OBJECTS)
	@ar rc $(NAME) $(OBJECTS)

.c.o: $(SOURCES)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

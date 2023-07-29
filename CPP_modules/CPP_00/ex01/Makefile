NAME = phonebooke

CPPFLAGS = -Wall -Werror -Wextra -std=c++98

SRC = phonebook.cpp


all : $(NAME)

$(NAME) :
	@c++ $(CPPFLAGS) $(SRC) -o $(NAME)
	@echo "\033[1;32m Compiling...\033[0;m"

clean :
	@rm -rf $(NAME)
	@echo "\033[1;31m Cleanin...\033[0;m"

fclean : clean 
	@rm -rf $(NAME)
	@echo "\033[1;31m Full Cleanin...\033[0;m"

re : fclean all

.PHONY : clean re all fclean
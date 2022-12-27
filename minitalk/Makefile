SERVER			 =	server
SERVER_SRC		 =	server.c
SERVER_OBJ		 =	$(SERVER_SRC:.c=.o)

CLIENT			 =	client
CLIENT_SRC		 =	client.c
CLIENT_OBJ		 =	$(CLIENT_SRC:.c=.o)

UTILS_SRC		=	minitalk_utils.c
UTILS_OBJ		=	$(UTILS_SRC:.c=.o)

SERVER_BONUS     =  server_bonus
SERVER_SRC_BONUS =  ./minitalk_bonus/server_bonus.c
SERVER_OBJ_BONUS =  $(SERVER_SRC_BONUS:.c=.o)

CLIENT_BONUS     =  client_bonus
CLIENT_SRC_BONUS =  ./minitalk_bonus/client_bonus.c
CLIENT_OBJ_BONUS =  $(CLIENT_SRC_BONUS:.c=.o)

UTILS_SRC_BONUS = 	./minitalk_bonus/minitalk_utils_bonus.c
UTILS_OBJ_BONUS = 	$(UTILS_SRC_BONUS:.c=.o)


CC				=	cc
RM 				=	rm -f
CFLAGS			= 	-Wall -Werror -Wextra

all : $(SERVER) $(CLIENT)

$(SERVER) : $(SERVER_OBJ) $(UTILS_OBJ)
	$(CC) $(CFLAGS) $(SERVER_SRC) $(UTILS_SRC) -o $(SERVER)
$(CLIENT) : $(CLIENT_OBJ) $(UTILS_OBJ)
	$(CC) $(CFLAGS) $(CLIENT_SRC) $(UTILS_SRC) -o $(CLIENT)

bonus : $(SERVER_BONUS) $(CLIENT_BONUS)

$(SERVER_BONUS) : $(SERVER_OBJ_BONUS) $(UTILS_OBJ_BONUS)
	$(CC) $(CFLAGS) $(SERVER_SRC_BONUS) $(UTILS_SRC_BONUS) -o $(SERVER_BONUS)
$(CLIENT_BONUS) : $(CLIENT_OBJ_BONUS) $(UTILS_OBJ_BONUS)
	$(CC) $(CFLAGS) $(CLIENT_SRC_BONUS) $(UTILS_SRC_BONUS) -o $(CLIENT_BONUS)

clean :
	$(RM) $(SERVER_OBJ) $(CLIENT_OBJ) $(UTILS_OBJ) $(SERVER_OBJ_BONUS) $(CLIENT_OBJ_BONUS) $(UTILS_OBJ_BONUS)

fclean : clean
	$(RM) $(SERVER) $(CLIENT) $(SERVER_BONUS) $(CLIENT_BONUS)

re : fclean all

reb : fclean bonus

test : all clean

testb : bonus clean

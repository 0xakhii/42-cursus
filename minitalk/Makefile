SERVER			=	server
SERVER_SRC		=	server.c
SERVER_OBJ		=	$(SERVER_SRC:.c=.o)

CLIENT			=	client
CLIENT_SRC		=	client.c 
CLIENT_OBJ		=	$(CLIENT_SRC:.c=.o)

UTILS_SRC		=	minitalk_utils.c 
UTILS_OBJ		=	$(UTILS_SRC:.c=.o)

CC				=	cc
RM 				=	rm -f
CFLAGS			= 	-Wall -Werror -Wextra

all : $(SERVER) $(CLIENT)

$(SERVER) : $(SERVER_OBJ) $(UTILS_OBJ)
	$(CC) $(CFLAGS) $(SERVER_SRC) $(UTILS_SRC) -o $(SERVER)
$(CLIENT) : $(CLIENT_OBJ) $(UTILS_OBJ)
	$(CC) $(CFLAGS) $(CLIENT_SRC) $(UTILS_SRC) -o $(CLIENT)
clean :
	$(RM) $(SERVER_OBJ) $(CLIENT_OBJ) $(UTILS_OBJ) $(SERVER_OBJ_BNS) $(CLIENT_OBJ_BNS) $(UTILS_OBJ_BNS)

fclean : clean
	$(RM) $(SERVER) $(CLIENT) $(SERVER_BNS) $(CLIENT_BNS)

re : fclean all


CLIENT = client
SERVER = server
LIBFT = libft.a

SERVER_SRC = server.c
CLIENT_SRC = client.c

C_FLAGS = -Wall -Wextra -Werror

all:  $(CLIENT) $(SERVER)

$(CLIENT): 
	cc $(C_FLAGS) $(CLIENT_SRC) -o $(CLIENT)
	cc $(C_FLAGS) $(SERVER_SRC) -o $(SERVER)

clean:
	rm -f $(SRC:.c=.o) 

fclean: clean
	rm -f $(CLIENT) $(SERVER)

re: fclean all
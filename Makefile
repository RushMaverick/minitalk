NAME = Minitalk

S = src/
I = includes/

CLIENT = client
SERVER = server
LIBFT = $I/libft.a

SERVER_SRC = $S/server.c
CLIENT_SRC = $S/client.c

C_FLAGS = -Wall -Wextra -Werror

all:  $(SERVER) $(CLIENT)

$(LIBFT):
	make -C includes all

$(SERVER): $(SERVER_SRC) $(LIBFT)
	cc $(C_FLAGS) $(SERVER_SRC) -o $(SERVER) $(LIBFT)

$(CLIENT): $(CLIENT_SRC) $(LIBFT)
	cc $(C_FLAGS) $(CLIENT_SRC) -o $(CLIENT) $(LIBFT)

clean:
	make -C includes clean

fclean: clean
	make -C includes fclean
	rm -f $(CLIENT) $(SERVER)

re: fclean all

.PHONY: all clean fclean re
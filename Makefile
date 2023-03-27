NAME = Minitalk

S = src/
I = includes/

CLIENT = client
SERVER = server
LIBFT = $I/libftprintf.a

SERVER_SRC = $S/server.c
CLIENT_SRC = $S/client.c

C_FLAGS = -Wall -Wextra -Werror

all:  $(SERVER) $(CLIENT)

$(LIBFT):
	make -C includes all

$(SERVER): $(SERVER_SRC) $(LIBFT)
	cc $(C_FLAGS) $(SERVER_SRC) $(LIBFT) -o $(SERVER) 

$(CLIENT): $(CLIENT_SRC) $(LIBFT)
	cc $(C_FLAGS) $(CLIENT_SRC) $(LIBFT) -o $(CLIENT) 

clean:
	make -C includes clean

fclean: clean
	make -C includes fclean
	rm -f $(CLIENT) $(SERVER)

re: fclean all

.PHONY: all clean fclean re
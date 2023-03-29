NAME = Minitalk

S = src
I = includes

CLIENT = client
SERVER = server
CLIENT_BONUS = client_bonus
SERVER_BONUS = server_bonus
LIBFT = $I/libftprintf.a

SERVER_SRC = $S/server.c
CLIENT_SRC = $S/client.c
SERVER_BONUS_SRC = $S/server_bonus.c
CLIENT_BONUS_SRC = $S/client_bonus.c

C_FLAGS = -Wall -Wextra -Werror

all:  $(SERVER) $(CLIENT)

$(LIBFT):
	make -C includes all

$(SERVER): $(SERVER_SRC) $(LIBFT)
	cc $(C_FLAGS) $(SERVER_SRC) $(LIBFT) -o $(SERVER) 

$(CLIENT): $(CLIENT_SRC) $(LIBFT)
	cc $(C_FLAGS) $(CLIENT_SRC) $(LIBFT) -o $(CLIENT)

bonus: $(SERVER_BONUS) $(CLIENT_BONUS)

$(SERVER_BONUS): $(SERVER_BONUS_SRC) $(LIBFT)
	cc $(C_FLAGS) $(SERVER_BONUS_SRC) $(LIBFT) -o $(SERVER_BONUS) 

$(CLIENT_BONUS): $(CLIENT_BONUS_SRC) $(LIBFT)
	cc $(C_FLAGS) $(CLIENT_BONUS_SRC) $(LIBFT) -o $(CLIENT_BONUS)

clean:
	make -C includes clean

fclean: clean
	make -C includes fclean
	rm -f $(CLIENT) $(SERVER) $(CLIENT_BONUS) $(SERVER_BONUS)

re: fclean all

.PHONY: all clean fclean re bonus
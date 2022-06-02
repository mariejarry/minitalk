SRCS =	server.c		\
		client.c		\



SERVER = server
CLIENT = client

OBJS = $(SRCS:.c=.o) 

CC = gcc

CC_FLAGS = -Wall -Werror -Wextra -g

.c.o :
	@echo "Compiling: $<"
	@$(CC) $(CC_FLAGS) -c $< -o $@

$(SERVER): $(OBJS)
	@echo "Minitalk Done !\n"
	@$(MAKE) -C libft
	@$(CC) $(CC_FLAGS) server.o libft/libft.a -o $(SERVER)

$(CLIENT): $(OBJS)
	@$(MAKE) -C libft
	@$(CC) $(CC_FLAGS) client.o libft/libft.a -o $(CLIENT)

all: $(SERVER) $(CLIENT)

clean:
	@$(MAKE) -C libft clean
	@rm -rf $(OBJS)

fclean: clean
	@$(MAKE) -C libft fclean
	@rm -f $(SERVER) $(CLIENT)

re: fclean all

bonus: all
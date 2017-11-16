# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akinfemi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/16 10:24:10 by akinfemi          #+#    #+#              #
#    Updated: 2017/11/16 11:35:44 by akinfemi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = client

SERVER = server

LIB = lib/lib.a

CFLAGS = -Wall -Werror -Wextra -I include/

CLIENT_SRC = client.c

SERVER_SRC = server.c

CLIENT_FILES = $(addprefix client_src/, $(CLIENT_SRC))

SERVER_FILES = $(addprefix server_src/, $(SERVER_SRC))

CLIENT_OBJ_FILES = $(CLIENT_FILES:.c=.o)

SERVER_OBJ_FILES = $(SERVER_FILES:.c=.o)

.PHONY = client server all clean fclean re

all : $(CLIENT) $(SERVER)

client: $(CLIENT)

server: $(SERVER)

$(CLIENT_OBJ_FILES):%.o: %.c
	@gcc -c $(CFLAGS) $< -o $@

$(SERVER_OBJ_FILES):%.o: %.c
	@gcc -c $(CFLAGS) $< -o $@

$(LIB):
	@make -C lib/
	@echo "Library created"

$(CLIENT): $(CLIENT_OBJ_FILES)
	@gcc $< $(LIB) -o $@
	@echo "Client created"

$(SERVER): $(SERVER_OBJ_FILES)
	@gcc $< $(LIB) -o $@
	@echo "Server created."

clean:
	@rm -f $(CLIENT_OBJ_FILES)
	@rm -f $(SERVER_OBJ_FILES)
	@echo "Object files removed"

fclean: clean
	@rm -f $(CLIENT)
	@echo "Client executable removed"
	@rm -f $(SERVER)
	@echo "Server executable removed"
	@make -C lib/ fclean
	@echo "Library cleaned"

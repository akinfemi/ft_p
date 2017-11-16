# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akinfemi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/16 10:24:10 by akinfemi          #+#    #+#              #
#    Updated: 2017/11/16 15:16:25 by akinfemi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLI_ENT = client

SER_VER = server

LIB = lib/lib.a

CFLAGS = -Wall -Werror -Wextra -I include/

CLIENT_SRC = client.c usage.c error.c

SERVER_SRC = server.c usage.c error.c

CLIENT_FILES = $(addprefix client_src/, $(CLIENT_SRC))

SERVER_FILES = $(addprefix server_src/, $(SERVER_SRC))

.PHONY = client server all clean fclean re

all : $(CLI_ENT) $(SER_VER)

client: $(CLI_ENT)

server: $(SER_VER)

$(CLIENT_OBJ_FILES):%.o: %.c
	@gcc -c $(CFLAGS) $< -o $@

$(SERVER_OBJ_FILES):%.o: %.c
	@gcc -c -o $@ $< $(CFLAGS)

$(LIB):
	@make -C lib/
	@echo "Library created"

$(CLI_ENT): $(CLIENT_OBJ_FILES) $(LIB)
	@gcc $< $(LIB) -o $@
	@echo "Client created"

$(SER_VER): $(SERVER_OBJ_FILES) $(LIB)  
	@gcc $< $(LIB) -o $(SER_VER)
	@echo "Server created."

clean:
	@rm -f $(CLIENT_OBJ_FILES)
	@rm -f $(SERVER_OBJ_FILES)
	@echo "Object files removed"

fclean: clean
	@rm -f $(CLI_ENT)
	@echo "Client executable removed"
	@rm -f $(SER_VER)
	@echo "Server executable removed"
	@make -C lib/ fclean
	@echo "Library cleaned"

re: fclean all

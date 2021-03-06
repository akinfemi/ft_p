# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akinfemi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/16 10:24:10 by akinfemi          #+#    #+#              #
#    Updated: 2017/11/16 19:49:47 by akinfemi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLI_ENT = client

SER_VER = server

LIB = lib/lib.a

CFLAGS = -Wall -Werror -Wextra -I include/ -g -fsanitize=address -fsanitize=undefined

CLIENT_SRC = client.c usage.c error.c handle_response.c utils.c client_handles.c \
				handle_path.c handle_put.c handle_get.c

SERVER_SRC = server.c usage.c error.c handle_client.c handle_command.c \
				handle.c dispatch.c handle_path.c

CLIENT_FILES = $(addprefix client_src/, $(CLIENT_SRC))

SERVER_FILES = $(addprefix server_src/, $(SERVER_SRC))

.PHONY = client server all clean fclean re

CLIENT_OBJ_FILES = $(CLIENT_FILES:.c=.o)

SERVER_OBJ_FILES = $(SERVER_FILES:.c=.o)

all : $(CLI_ENT) $(SER_VER)

$(LIB):
	@make -C lib/
	@echo "Library created"

$(CLIENT_OBJ_FILES):%.o: %.c
	@gcc -c $(CFLAGS) $< -o $@

$(SERVER_OBJ_FILES):%.o: %.c
	@gcc -c $(CFLAGS) $< -o $@

$(CLI_ENT): $(CLIENT_OBJ_FILES) $(LIB)
	@gcc -g -fsanitize=address -fsanitize=undefined $(CLIENT_OBJ_FILES) $(LIB) -o $(CLI_ENT)
	@echo "Client created"

$(SER_VER): $(SERVER_OBJ_FILES) $(LIB)  
	@gcc -g -fsanitize=address -fsanitize=undefined $(SERVER_OBJ_FILES) $(LIB) -o $(SER_VER)
	@echo "Server created."

clean:
	@rm -f $(CLIENT_OBJ_FILES)
	@rm -f $(SERVER_OBJ_FILES)
	@make -C lib/ clean

fclean: clean
	@rm -f $(CLI_ENT)
	@echo "Client executable removed"
	@rm -f $(SER_VER)
	@echo "Server executable removed"
	@make -C lib/ fclean
	@echo "Library cleaned"

re: fclean all

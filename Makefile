# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smuhamma <smuhamma@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/22 14:43:41 by smuhamma          #+#    #+#              #
#    Updated: 2023/01/29 17:53:13 by smuhamma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = client.c

SERVER = server.c

CLIENT_NAME = client

SERVER_NAME = server

CLIENT_B = client_bonus.c

SERVER_B = server_bonus.c

CLIENT_NAME_B = client_bonus

SERVER_NAME_B = server_bonus

CC = gcc

FLAGS = -Wall -Wextra -Werror

RM = rm -rf

all:  $(CLIENT_NAME) $(SERVER_NAME)

$(SERVER_NAME) : $(SERVER)
	$(CC) $(FLAGS) ft_util.c $(SERVER) -o $(SERVER_NAME)

$(CLIENT_NAME) : $(CLIENT)
	$(CC) $(FLAGS) ft_util.c $(CLIENT) -o $(CLIENT_NAME)

$(SERVER_NAME_B) : $(SERVER_B)
	$(CC) $(FLAGS) ft_util.c $(SERVER_B) -o $(SERVER_NAME_B)

$(CLIENT_NAME_B) : $(CLIENT_B)
	$(CC) $(FLAGS) ft_util.c $(CLIENT_B) -o $(CLIENT_NAME_B)

bonus: $(CLIENT_NAME_B) $(SERVER_NAME_B)

clean:
	$(RM) server.o client.o
	$(RM) server_bonus.o client_bonus.o

fclean: clean
	$(RM) server client
	$(RM) server_bonus client_bonus
	
re: fclean all bonus

.PHONY:	all clean fclean re
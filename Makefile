# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmanilow <hmanilow@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/07 20:00:12 by hmanilow          #+#    #+#              #
#    Updated: 2022/03/07 20:01:07 by hmanilow         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				=	minitalk

HEAD				=	minitalk.h
SRC_MAN				=	utils.c
SRC_CLIENT			=	client.c
SRC_SERVER			=	server.c

HEAD_BONUS			=	minitalk_bonus.h
SRC_BONUS			=	utils_bonus.c
SRC_CLIENT_BONUS	=	client_bonus.c
SRC_SERVER_BONUS	=	server_bonus.c

OBJ					=	$(patsubst %.c,%.o,$(SRC_MAN))
SERVER_OBJ			= 	$(patsubst %.c,%.o,$(SRC_SERVER))
CLIENT_OBJ			=	$(patsubst %.c,%.o,$(SRC_CLIENT))

OBJ_BONUS			=	$(patsubst %.c,%.o,$(SRC_BONUS))
SERVER_OBJ_BONUS	= 	$(patsubst %.c,%.o,$(SRC_SERVER_BONUS))
CLIENT_OBJ_BONUS	=	$(patsubst %.c,%.o,$(SRC_CLIENT_BONUS))

FLAGS				=	-Wall -Werror -Wextra

all: $(NAME)

$(NAME): server client

bonus: server_bonus client_bonus

server: $(SERVER_OBJ) $(OBJ)
	gcc $(SERVER_OBJ) $(OBJ) -o $@ -I $(HEAD)

client: $(CLIENT_OBJ) $(OBJ)
	gcc $(CLIENT_OBJ) $(OBJ) -o $@ -I $(HEAD)

server_bonus: $(SERVER_OBJ_BONUS) $(OBJ_BONUS)
	gcc $(SERVER_OBJ_BONUS) $(OBJ_BONUS) -o $@ -I $(HEAD_BONUS)

client_bonus: $(CLIENT_OBJ_BONUS) $(OBJ_BONUS)
	gcc $(CLIENT_OBJ_BONUS) $(OBJ_BONUS) -o $@ -I $(HEAD_BONUS)

%.o: %.c $(HEAD)
	gcc $(FLAGS) -c $< -o $@

clean:
	rm -f *.o *.g.gch *.d

fclean: clean
	rm -f client server server_bonus client_server

re: fclean all

.PHONY: all clean fclean re bonus

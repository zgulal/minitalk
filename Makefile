# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zgulal <zgulal@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/21 16:20:11 by zgulal            #+#    #+#              #
#    Updated: 2023/03/23 16:56:07 by zgulal           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1	= server

NAME2	= client

SRC		= server.c client.c

OBJ		= $(SRC:.c=.o)

all : $(OBJ)
	@make -C ./utils
	@gcc -Wall -Wextra -Werror server.c ./utils/libftprintf.a -o $(NAME1)
	@gcc -Wall -Wextra -Werror client.c ./utils/libftprintf.a -o $(NAME2)

clean :
	@make clean -C ./utils
	@rm -rf client.o server.o

fclean : clean
	@make fclean -C ./utils
	@rm -rf $(NAME1) $(NAME2)

re : fclean all

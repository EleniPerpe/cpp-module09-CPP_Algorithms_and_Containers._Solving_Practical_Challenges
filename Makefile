# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eleni <eleni@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/19 15:07:19 by eperperi          #+#    #+#              #
#    Updated: 2025/01/28 09:46:21 by eleni            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	bitCoin

CC				=	c++ -g -fsanitize=address

CFLAGS			=	-Wall -Werror -Wextra -std=c++11

SRC_FILES		=	main.cpp

OBJ_DIR			=	./obj

OBJ_FILES		= 	$(SRC_FILES:%.cpp=$(OBJ_DIR)/%.o)

all:	$(NAME)

$(NAME):	$(OBJ_FILES)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
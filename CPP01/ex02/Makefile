# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: felix <felix@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/26 12:43:53 by fwechsle          #+#    #+#              #
#    Updated: 2024/02/04 13:31:38 by felix            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= Hi_this_is_brain

SRC			=	main.cpp

OBJS		= $(SRC:.cpp=.o)

CC			= c++

CFLAGS		= -Wall -Werror -Wextra -std=c++98 -pedantic

RM			= rm -rf

all: $(NAME) 

$(NAME): $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re

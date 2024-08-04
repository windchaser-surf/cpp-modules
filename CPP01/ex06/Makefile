# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fwechsle <fwechsle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/26 12:43:53 by fwechsle          #+#    #+#              #
#    Updated: 2024/02/05 13:02:06 by fwechsle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= Harl_filter

SRC			=	main.cpp Harl.cpp

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

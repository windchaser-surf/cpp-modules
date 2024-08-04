# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fwechsle <fwechsle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/26 12:43:53 by fwechsle          #+#    #+#              #
#    Updated: 2024/03/12 11:02:59 by fwechsle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= cpp02

SRC			=	main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp

OBJS		= $(SRC:.cpp=.o)

CXX			= c++

CXXFLAGS		= -Wall -Werror -Wextra -std=c++98 -pedantic

RM			= rm -rf

all: $(NAME) 

$(NAME): $(OBJS) 
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re

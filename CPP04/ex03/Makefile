# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fwechsle <fwechsle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/26 12:43:53 by fwechsle          #+#    #+#              #
#    Updated: 2024/03/14 10:29:30 by fwechsle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= cpp03

SRC			=	main.cpp AMateria.cpp Character.cpp Cure.cpp Ice.cpp MateriaSource.cpp

OBJS		= $(SRC:.cpp=.o)

CXX			= c++

CXXFLAGS		= -Wall -Werror -Wextra -std=c++98 -pedantic -g

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

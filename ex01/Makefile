# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yeju <yeju@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/11 17:52:01 by yeju              #+#    #+#              #
#    Updated: 2022/04/11 17:52:20 by yeju             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Serialization
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror
C98 = -std=c++98
SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

$(NAME) : $(SRCS)
	$(CXX) $(CXXFLAGS) $(C98) -c $(SRCS)
	$(CXX) $(CXXFLAGS) $(C98) $(OBJS) -o $(NAME)

.PHONY : all clean fclean re
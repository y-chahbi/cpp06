# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ychahbi <ychahbi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/20 23:20:44 by ychahbi           #+#    #+#              #
#    Updated: 2024/01/20 23:21:39 by ychahbi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SUBJ = convert
SRC  = ScalarConverter.cpp main.cpp
CC= c++
FLAGS= -Wall -Wextra -Werror -std=c++98
RM= rm -f
OBJ_ALL = $(SRC:.cpp=.o)

all: $(SUBJ)

$(SUBJ): $(OBJ_ALL)
	$(CC) $(FLAGS) $^ -o $@

%.o: %.cpp ScalarConverter.hpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_ALL)

fclean: clean
	$(RM) $(SUBJ)

re: fclean all

.PHONY: clean%  
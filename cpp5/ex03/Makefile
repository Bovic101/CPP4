# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: victor-linux <victor-linux@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/30 08:39:03 by vodebunm          #+#    #+#              #
#    Updated: 2025/02/25 01:01:11 by victor-linu      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = intern

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp \
      ClassBureaucrat.cpp \
      AClassForm.cpp \
      PresidentialPardonForm.cpp \
      RobotomyRequestForm.cpp \
      ShrubberyCreationForm.cpp \
      Intern.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all


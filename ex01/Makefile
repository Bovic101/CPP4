# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vodebunm <vodebunm@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/30 08:39:03 by vodebunm          #+#    #+#              #
#    Updated: 2024/12/01 22:29:12 by vodebunm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = brain

# Source file for the project
SRC = main.cpp ClassAnimal.cpp ClassCat_Dog.cpp ClassWrongCat.cpp ClassBrain.cpp

# Object files will be derived from the source files
OBJ = $(SRC:.cpp=.o)

# Compiler to be used
CXX = c++

# Compilation flags for warnings and C++ standard compliance
CXXFLAGS =  -Wall -Wextra -Werror -std=c++98

# Command to remove files
RM = rm -f

# Default target to build the executable
all: $(NAME)

# Target to link the object files and create the executable
$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Target to remove the object files
clean:
	$(RM) $(OBJ)

# Target to remove both object files and the executable
fclean: clean
	$(RM) $(NAME)

# Target to clean and rebuild the project
re: fclean $(NAME)

# Special target to indicate that these targets do not represent files
.PHONY: all clean fclean re
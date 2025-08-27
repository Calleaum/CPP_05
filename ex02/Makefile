# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: calleaum <calleaum@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/07 08:37:36 by calleaum          #+#    #+#              #
#    Updated: 2025/08/26 15:09:44 by calleaum         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = Form

CXX     = c++
CXXFLAGS= -Wall -Wextra -Werror -std=c++98 -Iinclude

SRC     = src/Bureaucrat.cpp src/main.cpp src/AForm.cpp src/PresidentialPardonForm.cpp src/RobotomyRequestForm.cpp src/ShrubberyCreationForm.cpp
OBJ     = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
	@echo "\033[1;32mBuild complete: $(NAME)\033[0m"

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	@echo "\033[1;32mCleaned object files.\033[0m"

fclean: clean
	rm -f $(NAME)
	@echo "\033[1;32mRemoved executable.\033[0m"

re: fclean all

.PHONY: all clean fclean re

NAME = BureaucratForm
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = 	./main.cpp\
		./src/Bureaucrat.cpp\
		./src/AForm.cpp\
		./src/PresidentialPardonForm.cpp\
		./src/RobotomyRequestForm.cpp\
		./src/ShrubberyCreationForm.cpp\
		./src/Intern.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
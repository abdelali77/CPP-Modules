NAME = form28B

CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
GREEN=\033[0;32m
NC=\033[0m

SRC = main.cpp \
	  Bureaucrat.cpp \
	  AForm.cpp \
	  PresidentialPardonForm.cpp \
	  RobotomyRequestForm.cpp \
	  ShrubberyCreationForm.cpp

HDRS = Bureaucrat.hpp AForm.hpp PresidentialPardonForm.hpp RobotomyRequestForm.hpp ShrubberyCreationForm.hpp

OBJ = $(SRC:.cpp=.o)
%.o:%.cpp $(HDRS)
	@echo "$(GREEN)$<...$(NC)"
	@$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	@rm -rf $(OBJ)
	@rm -rf *_shrubbery

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
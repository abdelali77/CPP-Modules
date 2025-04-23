NAME = form

CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
GREEN=\033[0;32m
NC=\033[0m

SRC = main.cpp \
	  Bureaucrat.cpp \
	  Form.cpp
HDR = Bureaucrat.hpp Form.hpp

OBJ = $(SRC:.cpp=.o)
%.o:%.cpp $(HDR)
	@echo "$(GREEN)$<...$(NC)"
	@$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
NAME = array

CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

GREEN=\033[0;32m
NC=\033[0m

SRC = main.cpp
HDR = array.hpp

OBJ = $(SRC:.cpp=.o)

%.o:%.cpp $(HDR)
	@echo "$(GREEN)$<...$(NC)"
	@$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: re all clean fclean
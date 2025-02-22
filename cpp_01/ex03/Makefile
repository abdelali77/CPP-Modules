NAME = violence
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

GREEN=\033[0;32m
YELLOW=\033[0;33m
NC=\033[0m

SRC = main.cpp \
	  Weapon.cpp \
	  HumanA.cpp \
	  HumanB.cpp

HDR = Weapon.hpp
HDR1 = HumanA.hpp
HDR2 = HumanB.hpp

OBJ = $(SRC:.cpp=.o)

%.o: %.cpp $(HDR) $(HDR1) $(HDR2)
	@echo "$(GREEN)$<...$(NC)"
	@$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	@echo "$(YELLOW)objs cleaned$(NC)"
	@rm -rf $(OBJ)

fclean: clean
	@echo "$(YELLOW)program cleaned$(NC)"
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
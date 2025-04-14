NAME = materia

CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address -g

GREEN=\033[0;32m
YELLOW=\033[0;33m
NC=\033[0m

SRC = main.cpp \
	  AMateria.cpp \
	  Character.cpp \
	  Cure.cpp \
	  Ice.cpp \
	  MateriaSource.cpp

HDRS = AMateria.hpp Character.hpp Cure.hpp Ice.hpp ICharacter.hpp IMateriaSource.hpp MateriaSource.hpp

OBJS = $(SRC:.cpp=.o)

%.o:%.cpp $(HDRS)
	@echo "$(GREEN)$<...$(NC)"
	@$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean:
	@echo "$(YELLOW)objs cleaned$(NC)"
	@rm -rf $(OBJS)

fclean: clean
	@echo "$(YELLOW)program cleaned$(NC)"
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
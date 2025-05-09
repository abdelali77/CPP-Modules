NAME = convert

CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98 #-fsanitize=address -g

GREEN=\033[0;32m
NC=\033[0m

SRC = main.cpp \
	  ScalarConverter.cpp \
	  utils.cpp \
	  utils2.cpp

HDRS = ScalarConverter.hpp

OBJS = $(SRC:.cpp=.o)

%.o:%.cpp $(HDRS)
	@echo "$(GREEN)$<...$(NC)"
	@$(CC) $(FLAGS) -c $< -o $@

all:$(NAME)

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
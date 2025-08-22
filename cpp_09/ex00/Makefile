NAME = btc

CC := c++
FLAGS := -Wall -Wextra -Werror -std=c++98

GREEN=\033[0;32m
NC=\033[0m

SRCS = main.cpp \
	  BitcoinExchange.cpp \
	  utils.cpp
HDR = BitcoinExchange.hpp

OBJS = $(SRCS:.cpp=.o)

%.o:%.cpp $(HDR)
	@echo "$(GREEN)$<...$(NC)"
	@$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: re all clean fclean
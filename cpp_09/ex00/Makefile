NAME = btc

CC := c++
FLAGS := -Wall -Wextra -Werror -std=c++98

GREEN=\033[0;32m
NC=\033[0m

SRC = BitcoinExchange.cpp
HDR = BitcoinExchange.hpp

OBJS = $(SRC:.cpp=.o)

%.o:%.c $(HDR)
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
NAME = real

CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

GREEN=\033[0;32m
NC=\033[0m

SRCS = main.cpp \
	   Base.cpp \
	   type.cpp
HDRS = Base.hpp A.hpp B.hpp C.hpp type.hpp

OBJS = $(SRCS:.cpp=.o)

%.o:%.cpp $(HDRS)
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

.PHONY: all clean fclean re
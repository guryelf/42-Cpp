NAME = phonebook

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = phonebook.cpp contact.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS) -I .

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
NAME := PmergeMe
CC := c++

CFLAGS ?= -Wall -Werror -Wextra -std=c++98 -Wshadow -Wno-shadow
ifdef DEBUG
CFLAGS := -g $(CFLAGS)
endif
OBJECTS := main.o PmergeMe.o
OBJECTS := $(addprefix obj/,$(OBJECTS))
#INCLUDE := headers
#INCLUDE := $(addprefix -I,$(INCLUDE))
HEADER_FILES := PmergeMe.hpp
#HEADER_FILES := $(addprefix headers/,$(HEADER_FILES))

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

obj/%.o: %.cpp $(HEADER_FILES)
	@mkdir -p obj
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -f $(OBJECTS)
	@rm -rf obj

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: all

run: all
	./$(NAME) "1 1 +"

debug:
	$(MAKE) DEBUG=1

.PHONY: all clean fclean re bonus run debug

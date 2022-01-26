NAME := test_acountcpp.out
CC := c++

CFLAGS ?= -Wall -Werror -Wextra -std=c++98
ifdef DEBUG
CFLAGS := -g $(CFLAGS)
endif
OBJECTS := Account.o tests.o
OBJECTS := $(addprefix obj/,$(OBJECTS))
HEADER_FILES := Account.hpp

all: $(NAME)

$(NAME): $(OBJECTS)
	@$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

obj/%.o: %.cpp $(HEADER_FILES)
	@mkdir -p obj
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)
	@rm -rf obj

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: all

run: all
	@./$(NAME)

debug:
	$(MAKE) DEBUG=1

.PHONY: all clean fclean re bonus run debug

NAME := replace
CC := g++

CFLAGS ?= -Wall -Werror -Wextra
ifdef DEBUG
CFLAGS := -g $(CFLAGS)
endif
OBJECTS := main.o
OBJECTS := $(addprefix obj/,$(OBJECTS))
#INCLUDE := headers
#INCLUDE := $(addprefix -I,$(INCLUDE))
HEADER_FILES := 
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
	rm -f *.replace

re: fclean all

bonus: all

run: all
	./$(NAME) file1 "#\$$$$^" " "
	./$(NAME) file2 "John" "David"
	./$(NAME) file3 "a" "aaa"
	./$(NAME) file4 "a" "a"
	./$(NAME) filedoesntexist "John" "" extra agruments
	./$(NAME) filedoesntexist "John" ""
	./$(NAME) filedoesntexist "" "David"
	./$(NAME) "" "John" "David"
	./$(NAME) filedoesntexist "a" "a"

debug:
	$(MAKE) DEBUG=1

.PHONY: all clean fclean re bonus run debug

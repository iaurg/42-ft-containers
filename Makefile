CONTAINER = main

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address -g3

REMOVE = rm -rf

SOURCES_PATH = $(PWD)/tests

SOURCE_FILES =	$(shell ls ./tests | grep .cpp$)

SOURCES = $(addprefix $(SOURCES_PATH)/,$(SOURCE_FILES))

OBJECTS = ${SOURCES:%.cpp=%.o}

RM = rm -f

all: $(CONTAINER)

$(CONTAINER):  $(OBJECTS)
	$(CC) $(CFLAGS) -w $(OBJECTS) -o $(CONTAINER)

./tests/%.o: ./tests/%.cpp
	${CC} ${CFLAGS} -c $< -o $@

vector: $(CONTAINER)
	./$(CONTAINER) vector

re:	fclean all

clean:
	@$(REMOVE) $(OBJECTS)

fclean: clean
	@$(REMOVE) $(NAME)
	@$(REMOVE) $(CONTAINER)

.PHONY: all run ${CONTAINER} re fclean clean
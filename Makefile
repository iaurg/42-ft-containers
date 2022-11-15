NAME = ft_containers

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

REMOVE = rm -rf

SAFE_MKDIR = mkdir -p

SOURCES_PATH = $(PWD)

SOURCE_FILES =	$(shell ls ./ | grep .cpp$)

SOURCES = $(addprefix $(SOURCES_PATH)/,$(SOURCE_FILES))

OBJECTS = ${SOURCES:.cpp=.o}

.PHONY: all run valgrind re fclean clean

all: $(NAME)

$(NAME): $(OBJECTS)
	@$(CC) $(CFLAGS) \
	-w  $(OBJECTS) \
	-o $(NAME) \

$./%.o: $(SOURCES_PATH)/%.cpp
	@$(CC) $(CFLAGS) -I $(INCLUDES_PATH) -o $@ -c $<

re:	fclean all

clean:
	@$(REMOVE) $(OBJECTS)

fclean: clean
	@$(REMOVE) $(NAME)

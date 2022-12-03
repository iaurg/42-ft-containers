NAME = ft_container

CC = @c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address -g3

SOURCES = ./tests/main.cpp ./tests/vector.cpp

# Use same files from sources, but change .c to .o
OBJECTS = ${SOURCES:.cpp=.o}

# @ supress commands to show in terminal
RM = @rm -f

MSG1 = @echo "Compiled ✔︎"
MSG2 = @echo "Cleaned ✔︎"

all: $(NAME)

$(NAME): $(OBJECTS) $(SOURCES)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)
	$(MSG1)

# Clean generated .o files
clean:
	${RM} ${OBJECTS} ${BONUS_OBJECTS}
	${MSG2}

# Force clean all files generated on all
fclean: clean
	${RM} ${NAME}

# Regenarate compilation
re: fclean all

# phony will run, independent from the state of the file system, avoid make in files with same name
.PHONY: all clean fclean re
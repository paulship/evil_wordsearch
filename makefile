MAKEFLAGS += --no-builtin-rules

# Executables
CC := gcc

# List of sources
C_SOURCES = ./wordsearch.c \
            ./main.c

# The list of objects is the same as sources with '.c' changes to '.o'
OBJECTS = $(C_SOURCES:.c=.o)

# Rule for the final executable
wordsearch.out : $(OBJECTS)
	$(CC) $(OBJECTS) -o wordsearch.out

# General rule to turn any.c to any.o
%.o : %.c makefile
	$(CC) -c $(<) -o $(<:.c=.o) -Wall -Wpedantic -Wextra

# Cleanup - removes all object files and the output file
clean :
	rm $(OBJECTS)
	rm wordsearch.out



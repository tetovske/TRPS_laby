COMPILER = gcc

SRC = ./src/
INC = ./inc/

SOURCES = io_lib.c main.c list.c tools.c merge_sort.c binary_tree.c
HEADERS = header.h list.h sorts.h binary_tree.h
OBJECTS = $(SOURCES:.c=.o)
EXECUTABLE = laba
FLAGS = -Wall

all: $(OBJECTS)
	$(COMPILER) $^ -o $(EXECUTABLE)
	rm -rf $^

with_obj: $(OBJECTS)
	$(COMPILER) $^ -o $(EXECUTABLE)

%.o: $(SRC)%.c
	$(COMPILER) $(FLAGS) -I$(INC) -c $<

obj_clean:
	rm -rf $(OBJECTS)

clean:
	rm -rf $(OBJECTS) $(EXECUTABLE)

redo: clean all

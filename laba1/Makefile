COMPILER = gcc

SRC = ./src/
INC = ./inc/

SOURCES = io_lib.c main.c list.c tools.c merge_sort.c
HEADERS = header.h list.h sorts.h
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

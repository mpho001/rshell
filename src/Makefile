CC = g++
CC_FLAGS = -Wall -Werror -ansi -pedantic
EXEC = a.out
AUTOMAKE_OPTIONS = subdir-objects
SOURCES = $(wildcard *.cpp)
OBJECTS = Input.o Execute.o

$(EXEC): $(OBJECTS) -o $(EXEC)
	$(CC) $(OBJECTS) -o $(EXEC)

%.o: %.cpp
	$(CC) -c $(CC_FLAGS) $< -o $@

all: main.cpp $(OBJECTS)
	$(CC) $(CC_FLAGS) -o $(EXEC) main.cpp $(OBJECTS) 

clean:
	rm -f $(EXEC) $(OBJECTS)

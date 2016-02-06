CC = g++
CC_FLAGS = -Wall -Werror -ansi -pedantic
EXEC = a.out
AUTOMAKE_OPTIONS = subdir-objects
SOURCES = $(wildcard *.cpp)
OBJECTS = $(SOURCES:.cpp=.o)

$(EXEC): $(OBJECTS) -o $(EXEC)
	$(CC) $(OBJECTS) -o $(EXEC)

%.o: %.cpp
	$(CC) -c $(CC_FLAGS) $< -o $@

clean:
	rm -f $(EXEC) $(OBJECTS)

CC = g++
CC_FLAGS = -Wall -Werror -ansi -pedantic
EXEC = a.out

VPATH = src
BUILDDIR = build/src

#AUTOMAKE_OPTIONS = subdir-objects
SOURCES = $(wildcard *.cpp)
OBJECTS = $(SOURCES:.cpp=.o)
#OBJECTS = Input.o Execute.o

$(BUILDDIR)$(EXEC): $(OBJECTS)
   #	-o $(EXEC)
	$(CC) $(OBJECTS) -o $(EXEC)

$(BUILDDIR)%.o: %.cpp
	$(CC) -c $(CC_FLAGS) $< -o $@

# removed main.cpp after exec
all: main.cpp $(OBJECTS)
	$(CC) $(CC_FLAGS) -o $(EXEC) $(OBJECTS) 

clean:
	rm -f $(EXEC) $(OBJECTS)

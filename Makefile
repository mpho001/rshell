#CC = g++
#CC_FLAGS = -Wall -Werror -ansi -pedantic
#EXEC = a.out
#AUTOMAKE_OPTIONS = subdir-objects
#SOURCES = $(wildcard *.cpp)
#OBJECTS = $(SOURCES:.cpp=.o)

#$(EXEC): $(OBJECTS) -o $(EXEC)
#	$(CC) $(OBJECTS) -o $(EXEC)

#%.o: %.cpp
#	$(CC) -c $(CC_FLAGS) $< -o $@
#
#clean:
#	rm -f $(EXEC) $(OBJECTS)

CC = g++
CC_FLAGS = -Wall -Werror -ansi -pedantic
EXEC = a.out

SOURCEDIR = src
BUILDDIR = src

#AUTOMAKE_OPTIONS = subdir-objects
SOURCES = $(wildcard $(SOURCEDIR)/*.cpp)
OBJECTS = $(patsubst $(SOURCEDIR)/%.cpp,$(BUILDDIR)/%.o,$(SOURCES))
#OBJECTS = $(SOURCES:.cpp=.o)
#OBJECTS = Input.o Execute.o

$(BUILDDIR)/$(EXEC): $(OBJECTS)
   #	-o $(EXEC)
	$(CC) $(OBJECTS) -o $(SOURCEDIR)/$(EXEC)

$(OBJECTS): $(BUILDDIR)/%.o: $(SOURCEDIR)/%.cpp
	$(CC) -c $(CC_FLAGS) $< -o $@

# removed main.cpp after exec
all: $(SOURCEDIR)/main.cpp $(OBJECTS)
	$(CC) $(CC_FLAGS) -o $(SOURCEDIR)/$(EXEC) $(OBJECTS) 

clean:
	rm -f $(OBJECTS) $(BUILDDIR)/$(EXEC)

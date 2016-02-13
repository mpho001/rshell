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
EXECU = rshell

ODIR = bin
dummy_build_folder := $(shell mkdir -p $(ODIR))

SOURCEDIR = src
BUILDDIR = bin

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

rshell: $(SOURCEDIR)/main.cpp $(OBJECTS)
	$(CC) $(CC_FLAGS) -o $(BUILDDIR)/$(EXECU) $(OBJECTS)

clean:
	rm -f $(OBJECTS) $(BUILDDIR)/$(EXECU)

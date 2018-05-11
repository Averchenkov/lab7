CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=lab7.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=lab7

all: $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

%.o: %.cpp 
	$(CC) $(CFLAGS) $< -o $@

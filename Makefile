CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=Vertex.cpp Arc.cpp Graph.cpp input.cpp menu.cpp main.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=lab7

all: $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

%.o: %.cpp Vertex.h Arc.h Graph.h function.h
	$(CC) $(CFLAGS) $< -o $@

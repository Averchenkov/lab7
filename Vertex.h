#ifndef VERTEX_H
#define VERTEX_H 

#include "Graph.h"
#include <string>

class Graph;

class Vertex
{
	friend Graph;
private:
	std::string name;
public:
	Vertex(std::string);
	~Vertex();
	Vertex(const Vertex &);
	std::string get();
	void set(std::string);
	friend std::ostream &operator <<(std::ostream &os, Graph & graph);
};

#endif


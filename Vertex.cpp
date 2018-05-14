#include "Vertex.h"
#include <iostream>
#include <string>

using namespace std;

Vertex::Vertex(string name)
{
	this->name = name;
}
Vertex::~Vertex()
{
}
Vertex::Vertex(const Vertex &other)
{
	name = other.name;
}
string Vertex::get()
{
	return name;
}
void Vertex::set(string name)
{
	this->name = name;
}
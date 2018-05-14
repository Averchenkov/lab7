#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include "Vertex.h"
#include "Arc.h"
#include "function.h"

class Vertex;
class Arc;

class Graph
{
private:
	std::vector<Vertex> vertex;
	std::vector<Arc> arc;
public:
	Graph();
	~Graph();
	Graph(const Graph &);
	Graph &operator =(const Graph &);
	bool check_vertex_name(std::string);
	bool check_arc_name(std::string, std::string);
	void new_vetex(std::string);
	void connected(std::string, std::string);
	void delete_vertex(std::string);
	void delete_arc(std::string, std::string);
	void rename_vertex(std::string, std::string);
	void output_vertex();
	void output_arc_start(std::string);
	void output_arc_finish(std::string);
	void output_arc();
	friend std::ostream &operator <<(std::ostream &, Graph &);
	friend std::istream & operator>>(std::istream &, Graph &);
};
std::ostream &operator <<(std::ostream &, Graph &);
std::istream & operator>>(std::istream &, Graph &);
	
#endif